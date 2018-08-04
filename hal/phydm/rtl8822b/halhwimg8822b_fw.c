/******************************************************************************
*
* Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
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
* You should have received a copy of the GNU General Public License along with
* this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
*
*
******************************************************************************/

/*Image2HeaderVersion: 2.16*/
#include "mp_precomp.h"
#include "../phydm_precomp.h"

#include "../../rtl8822b/hal8822b_fw.h"


#if (RTL8822B_SUPPORT == 1)
#if (defined(CONFIG_AP_WOWLAN) || (DM_ODM_SUPPORT_TYPE & (ODM_AP)))

void
odm_read_firmware_mp_8822b_fw_ap(
	struct PHY_DM_STRUCT    *p_dm_odm,
	u8       *p_firmware,
	u32       *p_firmware_size
)
{
#if (DM_ODM_SUPPORT_TYPE & (ODM_CE))
	*((SIZE_PTR *)p_firmware) = (SIZE_PTR)array_mp_8822b_fw_ap;
#else
	odm_move_memory(p_dm_odm, p_firmware, array_mp_8822b_fw_ap, array_length_mp_8822b_fw_ap);
#endif
	*p_firmware_size = array_length_mp_8822b_fw_ap;
}


#endif /* #if (defined(CONFIG_AP_WOWLAN) || (DM_ODM_SUPPORT_TYPE & (ODM_AP)) */


#if (DM_ODM_SUPPORT_TYPE & (ODM_WIN)) || (DM_ODM_SUPPORT_TYPE & (ODM_CE))

void
odm_read_firmware_mp_8822b_fw_nic(
	struct PHY_DM_STRUCT    *p_dm_odm,
	u8       *p_firmware,
	u32       *p_firmware_size
)
{
#if (DM_ODM_SUPPORT_TYPE & (ODM_CE))
	*((SIZE_PTR *)p_firmware) = (SIZE_PTR)array_mp_8822b_fw_nic;
#else
	odm_move_memory(p_dm_odm, p_firmware, array_mp_8822b_fw_nic, array_length_mp_8822b_fw_nic);
#endif
	*p_firmware_size = array_length_mp_8822b_fw_nic;
}

void
odm_read_firmware_mp_8822b_fw_wowlan(
	struct PHY_DM_STRUCT    *p_dm_odm,
	u8       *p_firmware,
	u32       *p_firmware_size
)
{
#if (DM_ODM_SUPPORT_TYPE & (ODM_CE))
	*((SIZE_PTR *)p_firmware) = (SIZE_PTR)array_mp_8822b_fw_wowlan;
#else
	odm_move_memory(p_dm_odm, p_firmware, array_mp_8822b_fw_wowlan, array_length_mp_8822b_fw_wowlan);
#endif
	*p_firmware_size = array_length_mp_8822b_fw_wowlan;
}



#endif /* end of (defined(CONFIG_AP_WOWLAN) || (DM_ODM_SUPPORT_TYPE & (ODM_AP)))*/

#endif /* end of HWIMG_SUPPORT*/
