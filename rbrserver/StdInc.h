/
 * Solution   : Euro Truck Multiplayer RBR
 * Project    : Euro Truck Multiplayer RBR - Server
 * Licence    : GNU GPL v2
 * File       : StdInc.h
 *System Inc :
 * Description: Project By RBR Team
 * Dev Sun : 
 *Site :BlackBox.ac  <carlos_sk8ever_@hotmail.com>>
 *
 */

#pragma once
#define SERVER

// RakNet Sourcer MP
#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>
#include <RPC4Plugin.h>

//  includes
#include <iostream>
#include <list>
#include <map>
#include <locale.h>

#if defined _WIN32
        #include <windows.h>
        #include <sys/stat.h>
#else
        #include <stdlib.h>
        #include <string.h>
        #include <stdio.h>
#endif
#include <stdarg.h>
#include <sstream>
#include <time.h>
#include <assert.h>

// Squirrel Conection
#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdaux.h>
#include <sqstdblob.h>
#include <sqstdio.h>
#include <sqstdsystem.h>
#include <sqstdmath.h>
#include <sqstdstring.h>
#include <sqstate.h>
#include <sqvm.h>

// Network = Default
#include <network/CRPCManager.h>

// Tiny XML = System Save
#include "ticpp.h"
#include "tinyxml.h"

// Includy Multiplayer RBR
#include "Main.h"
#include <Shared.h>
#include <CString.h>
#include "CCommandSystem.h"
#include "CConfig.h"
#include "CPacketManager.h"
#include "CPlayerManager.h"
#include "CQuery.h"
#include "CNetworkManager.h"
#include "CPlayer.h"
#include "CServer.h"
#include "CLog.h"

// Scripts
#include "CSquirrelArguments.h"
#include "CEventManager.h"
#include "CResource.h"
#include "CResourceScript.h"
#include "CResourceManager.h"
