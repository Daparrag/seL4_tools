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

#pragma once

#define RH3ULCB_SCIF0_BASE		0xe6e60000
#define RH3ULCB_SCIF1_BASE		0xe6e68000
#define RH3ULCB_SCIF2_BASE		0xe6e88000
#define RH3ULCB_SCIF3_BASE		0xe6c50000
#define RH3ULCB_SCIF4_BASE		0xe6c40000
#define RH3ULCB_SCIF5_BASE		0xe6f30000


/* use the SCIF channel 2 as UART  */
#define UART_PPTR              RH3ULCB_SCIF2_BASE










// #define UARTA_BASE          0x03100000
// #define UARTB_BASE          0x03110000
// #define UARTC_BASE          0x0c280000
// #define UARTD_BASE          0x03130000

// #define UART_PPTR           UARTA_BASE


