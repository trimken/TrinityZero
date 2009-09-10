/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _ITEM_ENCHANTING_MGR_H
#define _ITEM_ENCHANTING_MGR_H

#include "Common.h"

struct RandomPropertiesPoints
{
    //uint32    itemLevel;
    uint32    EpicPropertiesPoints[5];
    uint32    RarePropertiesPoints[5];
    uint32    UncommonPropertiesPoints[5];
};

typedef std::map<uint32, RandomPropertiesPoints>   RandomPropertiesPointsStore;

class ItemEnchMgr
{
  public:
     ItemEnchMgr();
	 ~ItemEnchMgr();

  public:
	void LoadRandomEnchantmentsTable();
	void LoadRandomPropPointsTable();
    uint32 GetItemEnchantMod(uint32 entry);
    uint32 GenerateEnchSuffixFactor(uint32 item_id);

	RandomPropertiesPoints const *GetRandomPropPoints(uint32 itemlevel) const
	{
		RandomPropertiesPointsStore::const_iterator itr = mRandomPropertiesPoints.find(itemlevel);
		if(itr != mRandomPropertiesPoints.end())
		   return &itr->second;
		return NULL;
	}

   private:
    RandomPropertiesPointsStore  mRandomPropertiesPoints;
};

#define iEnchMgr Trinity::Singleton<ItemEnchMgr>::Instance()
#endif
