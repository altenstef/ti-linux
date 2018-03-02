/*
 * Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __ICSS_SWITCH_HSR_PRP_H
#define __ICSS_SWITCH_HSR_PRP_H

#define HSR_TAG_SIZE                     6       /* HSR tag size */

#define LRE_HSR_MODE                      0x1E76
#define MODEH                             0x01
#define MODEN                             0x02
#define MODET                             0x03
#define MODEU                             0x04
#define MODEM                             0x05

/* PRU0 DMEM */
#define DBG_START                         0x1C00

#define DUPLICATE_HOST_TABLE              0x0200
#define DUPLICATE_HOST_TABLE_END          0x19f4

/* PRU1 DMEM */
#define DUPLICATE_PORT_TABLE_PRU0         0x0200
#define DUPLICATE_PORT_TABLE_PRU0_END     0x0df4
#define DUPLICATE_PORT_TABLE_PRU1         0x0E00
#define DUPLICATE_PORT_TABLE_PRU1_END     0x19f4

/* Size and setup (N and M) of duplicate host table */
#define DUPLICATE_HOST_TABLE_SIZE         0x1C08
/* Size and setup (N and M) of duplicate port table (HSR Only) */
#define DUPLICATE_PORT_TABLE_SIZE         0x1C1C
/* Time after which a node entry is cleared (10ms resolution) */
#define NODE_FORGET_TIME                  0x1C20
/* Time after which an entry is removed from the dup table (10ms resolution) */
#define DUPLI_FORGET_TIME                 0x1C24
/* Time interval to check the port duplicate table */
#define DUPLI_PORT_CHECK_RESO             0x1C2C
/* Time interval to check the host duplicate table */
#define DUPLI_HOST_CHECK_RESO             0x1C30
/* NodeTable | Host | Port */
#define HOST_TIMER_CHECK_FLAGS            0x1C38
/* Arbitration flag for the host duplicate t */
#define HOST_DUPLICATE_ARBITRATION        0x1C3C
/* Supervision address in HSR */
#define SUP_ADDR                          0x1C4C
#define SUP_ADDR_LOW                      0x1C50

/* Time in TimeTicks (1/100s) */
#define DUPLICATE_FORGET_TIME_400_MS      40
/* Time in TimeTicks (1/100s) */
#define DUPLICATE_FORGET_TIME_400_MS_PRP  0x0028
/* Time in TimeTicks (1/100s) */
#define NODE_FORGET_TIME_60000_MS         6000

#define DUPLICATE_PORT_TABLE_DMEM_SIZE        0x0C00
#define DUPLICATE_HOST_TABLE_DMEM_SIZE        0x1800
#define LRE_STATS_DMEM_SIZE_HSR               0x0064
#define LRE_STATS_DMEM_SIZE                   0x0070
#define DEBUG_COUNTER_DMEM_SIZE               0x0050

#define DUPLICATE_HOST_TABLE_SIZE_INIT         0x00800004  /* N = 128, M = 4 */
#define DUPLICATE_PORT_TABLE_SIZE_INIT         0x00400004  /* N = 64, M = 4 */
#define MASTER_SLAVE_BUSY_BITS_CLEAR           0x00000000
#define TABLE_CHECK_RESOLUTION_10_MS           0x0000000A
#define SUP_ADDRESS_INIT_OCTETS_HIGH           0x004E1501  /* 01-15-4E-00- */
#define SUP_ADDRESS_INIT_OCTETS_LOW            0x00000001  /* -01-00 */

/* SHARED RAM */

/* 8 bytes of VLAN PCP to RX QUEUE MAPPING */
#define QUEUE_2_PCP_MAP_OFFSET                 0x120
#define LRE_START                              0x140

/* Number of frames successfully sent over port A/B that are HSR/PRP tagged */
#define LRE_CNT_TX_A                           (LRE_START + 4)

#define LRE_DUPLICATE_DISCARD                  (LRE_START + 104)
#define LRE_TRANSPARENT_RECEPTION              (LRE_START + 108)

#define IEC62439_CONST_DUPLICATE_ACCEPT                 0x01
#define IEC62439_CONST_DUPLICATE_DISCARD                0x02
#define IEC62439_CONST_TRANSPARENT_RECEPTION_REMOVE_RCT 0x01
#define IEC62439_CONST_TRANSPARENT_RECEPTION_PASS_RCT   0x02

/* PRU1 DMEM
 * Multicast filter defines & offsets
 */
#define M_MULTICAST_TABLE_SEARCH_OP_CONTROL_BIT         0xE0
/* one byte field :
 * 0 -> multicast filtering disabled
 * 1 -> multicast filtering enabled
 */
#define MULTICAST_FILTER_DISABLED                       0x00
#define MULTICAST_FILTER_ENABLED                        0x01
#define MULTICAST_FILTER_MASK                           0xE4
#define MULTICAST_FILTER_TABLE                          0x100
#define MULTICAST_TABLE_SIZE                            256
#define MULTICAST_FILTER_HOST_RCV_ALLOWED               0x01
#define MULTICAST_FILTER_HOST_RCV_NOT_ALLOWED           0x00

#define NODE_TABLE_NEW			  0x3000

#define NT_REM_NODE_TYPE_MASK     0x1F
#define NT_REM_NODE_TYPE_SHIFT    0x00

#define NT_REM_NODE_TYPE_SANA     0x01
#define NT_REM_NODE_TYPE_SANB     0x02
#define NT_REM_NODE_TYPE_SANAB    0x03
#define NT_REM_NODE_TYPE_DAN      0x04
#define NT_REM_NODE_TYPE_REDBOX   0x08
#define NT_REM_NODE_TYPE_VDAN     0x10

#define NT_REM_NODE_HSR_BIT       0x20 /* if set node is HSR */

#define NT_REM_NODE_DUP_MASK      0xC0
#define NT_REM_NODE_DUP_SHIFT     0x06

#define NT_REM_NODE_DUP_ACCEPT    0x40 /* Node ent duplicate type: DupAccept */
#define NT_REM_NODE_DUP_DISCARD   0x80 /* Node ent duplicate type: DupDiscard */

/* HOST_TIMER_CHECK_FLAGS bits */
#define HOST_TIMER_NODE_TABLE_CHECK_BIT    BIT(0)
#define HOST_TIMER_NODE_TABLE_CLEAR_BIT    BIT(4)
#define HOST_TIMER_HOST_TABLE_CHECK_BIT    BIT(8)
#define HOST_TIMER_P1_TABLE_CHECK_BIT      BIT(16)
#define HOST_TIMER_P2_TABLE_CHECK_BIT      BIT(24)
#define HOST_TIMER_PORT_TABLE_CHECK_BITS \
	(HOST_TIMER_P1_TABLE_CHECK_BIT | HOST_TIMER_P2_TABLE_CHECK_BIT)

#endif /* __ICSS_SWITCH_HSR_PRP_H */
