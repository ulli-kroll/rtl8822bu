/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/
#ifndef __HAL_IC_CFG_H__
#define __HAL_IC_CFG_H__

#define RTL8188E_SUPPORT				0
#define RTL8812A_SUPPORT				0
#define RTL8821A_SUPPORT				0
#define RTL8723B_SUPPORT				0
#define RTL8723D_SUPPORT				0
#define RTL8192E_SUPPORT				0
#define RTL8814A_SUPPORT				0
#define RTL8195A_SUPPORT				0
#define RTL8197F_SUPPORT				0
#define RTL8703B_SUPPORT				0
#define RTL8188F_SUPPORT				0
#define RTL8822B_SUPPORT				0
#define RTL8821B_SUPPORT				0
#define RTL8821C_SUPPORT				0
#define RTL8710B_SUPPORT				0
#define RTL8814B_SUPPORT				0

/*#if (RTL8188E_SUPPORT==1)*/
#define RATE_ADAPTIVE_SUPPORT			0
#define POWER_TRAINING_ACTIVE			0

#ifdef CONFIG_MULTIDRV
#endif

#ifdef CONFIG_RTL8822B
	#undef RTL8822B_SUPPORT
	#define RTL8822B_SUPPORT				1
	#ifndef CONFIG_FW_C2H_PKT
		#define CONFIG_FW_C2H_PKT
	#endif /* CONFIG_FW_C2H_PKT */
	#define RTW_TX_PA_BIAS	/* Adjust TX PA Bias from eFuse */
	#define CONFIG_DFS	/* Enable 5G band 2&3 channel */

	#ifdef CONFIG_WOWLAN
		#define CONFIG_GTK_OL
		#define CONFIG_ARP_KEEP_ALIVE
		#ifndef CONFIG_DEFAULT_PATTERNS_EN
			#warning "Force to enable CONFIG_DEFAULT_PATTERNS_EN under WOW"
			#define CONFIG_DEFAULT_PATTERNS_EN
		#endif /* !CONFIG_DEFAULT_PATTERNS_EN */

		#ifdef CONFIG_GPIO_WAKEUP
			#ifndef WAKEUP_GPIO_IDX
				#define WAKEUP_GPIO_IDX	6	/* WIFI Chip Side */
			#endif /* !WAKEUP_GPIO_IDX */
		#endif /* CONFIG_GPIO_WAKEUP */

	#endif /* CONFIG_WOWLAN */
	#ifdef CONFIG_CONCURRENT_MODE
		#define CONFIG_AP_PORT_SWAP
		#define CONFIG_FW_MULTI_PORT_SUPPORT
	#endif /* CONFIG_CONCURRENT_MODE */

	/*
	 * Beamforming related definition
	 */
	/* Beamforming mechanism is on driver not phydm, always disable it */
	#define BEAMFORMING_SUPPORT				0
	/* Only support new beamforming mechanism */
	#ifdef CONFIG_BEAMFORMING
		#define RTW_BEAMFORMING_VERSION_2
	#endif /* CONFIG_BEAMFORMING */

	#ifndef CONFIG_RTW_MAC_HIDDEN_RPT
		#define CONFIG_RTW_MAC_HIDDEN_RPT
	#endif /* CONFIG_RTW_MAC_HIDDEN_RPT */

	#ifndef DBG_RX_DFRAME_RAW_DATA
		#define DBG_RX_DFRAME_RAW_DATA
	#endif /* DBG_RX_DFRAME_RAW_DATA */

	#ifndef RTW_IQK_FW_OFFLOAD
		#define RTW_IQK_FW_OFFLOAD
	#endif /* RTW_IQK_FW_OFFLOAD */
#endif /* CONFIG_RTL8822B */

#endif /*__HAL_IC_CFG_H__*/
