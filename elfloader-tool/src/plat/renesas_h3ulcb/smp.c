/*
 * Copyright 2019, Diego Guzman <daparrag@correo.udistrital.edu.co>
 * implemented for renesas rcar-H3 ULCB starter kit. 
 *
 * Copyright 2018, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(DATA61_GPL)
 */

/* The renesas H3 ULCB has two clusters (A57 and A53), and each cluster has 4
 * cores. only one of the clusters can be used as master boot at any given time
 *  it should be configure via physical pin at SW6.
 *
 */

#define MAX_CORES           8
#define MAX_CLUSTERS        2
#define CORES_PER_CLUSTER   4
#define CLUSTER_ID_SHIFT    8

extern void core_entry_head(void);


void init_cpus(void)
{
	int nodes = CONFIG_MAX_NUM_NODES;
    if (nodes > MAX_CORES) {
        printf("CONFIG_MAX_NUM_NODES %d is greater than max number cores %d, will abort\n",
                CONFIG_MAX_NUM_NODES, MAX_CORES);
        abort();
    }

    for (int i = 1; i < nodes; i++)
    {
    	/* code */
    	int core_id = i % CORES_PER_CLUSTER;
        int cluster_id = i / CORES_PER_CLUSTER;
        int logic_id = i;
        uint64_t cpuid = core_id | (cluster_id << CLUSTER_ID_SHIFT);
        int ret = psci_cpu_on(cpuid, (unsigned long)core_entry_head, (unsigned long)&core_stacks[logic_id][0]);
        if (ret != PSCI_SUCCESS) {
        	
             printf("Failed to bring up core %d with error %d\n", i, ret);
            abort();
        }
        while (!is_core_up(i));
        printf("Core %d is up with logic ID %d\n", i, i);
    }
    
     /* set the logic id for the booting core */
    MSR("tpidr_el1", 0);

}