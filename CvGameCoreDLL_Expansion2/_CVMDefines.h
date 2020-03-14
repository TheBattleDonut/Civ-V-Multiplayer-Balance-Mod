#pragma once

#ifndef CVM_DEFINES_LIST

#define CVM_DEFINES_LIST

// Custom GUID for Civ V Multiplayer Balance Mod
#define CVM_GUID

// AI changes
#define CVM_AI_NO_WORLD_WONDERS
#define CVM_AI_NO_BUILDING_SETTLERS
#define CVM_AI_NO_MAKING_PROPHETS
#define CVM_AI_NO_WAR_DECLARATION
#define CVM_AI_NO_GOLD_GIFTS_CS
#define CVM_AI_ONLY_LUX_TRADES
#define CVM_AI_NO_VOTES

// Mechanical changes
#define CVM_RANDOMIZE_TURN_ACTIVATION_ORDER
#define CVM_NO_SHIFT_MOVE
#define CVM_ALWAYS_SEE_BARB_CAMPS
#define CVM_DISABLE_TURN_TIMER_RESET_ON_AUTOMATION
#define CVM_CS_WAR_AFTER_PEACE
#define CVM_NO_RADAR
#define CVM_UN_WORLD_LEADER_VOTES
#define CVM_NO_IMPROVEMENT_IN_ENNEMY_TERRITORY_AT_WAR
#define CVM_NO_WAR_AFTER_CS_ALLIED
#define CVM_PAUSE_AFTER_DISCONNECT
#define CVM_NO_INPUT_DURING_TURN_ROLL_OVER

// Removals
#define CVM_BAN_OBSERVATORIES

// Bug Fixes
#define CVM_CITADEL_BUG_FIX
#define CVM_TRIPLE_BARB_SPAWN_FIX
#define CVM_AUTOSAVE_FIX

// Policy changes
#define CVM_LIBERTY_FINISHER_FREE_GREAT_PROPHET
#define CVM_PATRONAGE_FINISHER_GIFTED_GREAT_PEOPLE

// Refactor
#define CVM_PLAYER_ACTIVATION_MOVED_TO_UPDATE

// Civ changes
#define CVM_IROQUOIS_UA_FIX // Fix Iroquois movement from forest to road

// Debug minidump
#define GAK_DEBUG_MINIDUMP

// Game Event wrappers
#include "Lua\CvLuaSupport.h"
#define GAMEEVENTINVOKE_HOOK gCustomMods.eventHook

#define GAMEEVENTRETURN_NONE  -1
#define GAMEEVENTRETURN_FALSE  0
#define GAMEEVENTRETURN_TRUE   1
#define GAMEEVENTRETURN_HOOK   GAMEEVENTRETURN_TRUE
#define GAMEEVENTRETURN_VALUE  GAMEEVENTRETURN_TRUE

#define GAMEEVENT_WorldTurnStart "WorldTurnStart", ""
#define GAMEEVENT_WorldTurnEnd   "WorldTurnEnd",   ""

class CustomMods {
public:
    CustomMods();

    int eventHook(const char* szName, const char* p, ...);
    int eventTestAll(const char* szName, const char* p, ...);

    int eventHook(const char* szName, CvLuaArgsHandle &args);
    int eventTestAll(const char* szName, CvLuaArgsHandle &args);
};

extern CustomMods gCustomMods;
#endif