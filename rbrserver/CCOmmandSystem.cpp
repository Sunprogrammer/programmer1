/**********************************************************************
 *
 * Solution   : Euro Truck Multiplayer RBR
 * Project    : Euro Truck Multiplayer RBR - Server
 * Licence    : GNU GPL v2
 * File       : CCommandSystem.cpp
 * Description: Project By RBR Team
 * Dev Sun : 
 *Site :BlackBox.ac  <carlos_sk8ever_@hotmail.com>>
 *
 **********************************************************************/
 
 #include "StdInc.h"

extern CServer *g_pServer;

CCommandSystem::CCommandSystem()
{
        
}

CCommandSystem::~CCommandSystem()
{

}

void CCommandSystem::ParseCommand ( const char * szInputB )
{
//
szInput.Set(szInputB);

//

 if(szInput.IsNotEmpty()) 
        {
                size_t sSpace = szInput.Find(' ', 0);
                CString szCommand = szInput.CutStr(0, sSpace++);
                CString szParams = szInput.CutStr(sSpace, (szInput.GetLength() - sSpace));
        //        
                if ( szCommand.IsEmpty( ) )
                        return;

 ProcessCommand ( szCommand.Get(), (!szParams.GetLength() ? "" : szParams.Get()) );
        }
}

void CCommandSystem::AddCommand ( const char *szCommand, Cmd_Function Function )
{

//
  CCommand * pCommand = new CCommand();
  //
   strcpy(pCommand->m_szCommand, szCommand);
   //
    pCommand->m_Function = Function;
    //
     m_Commands.push_back(pCommand);
}

void CCommandSystem::RemoveCommand ( const char *szCommand )
{
        CCommand * pCommand = NULL;
        std::list<CCommand *>::iterator iter;
        for ( iter = m_Commands.begin(); iter != m_Commands.end(); iter ++ )
        {
                if ( !strcmp( (*iter)->m_szCommand , szCommand ) )
                {
                        pCommand = (*iter);
                }
        }

        if ( pCommand )
        {
                m_Commands.remove ( pCommand );
                delete pCommand;
        }
}

bool CCommandSystem::ProcessCommand ( const char *szCommand, const char *szParams )
{
        CCommand * pCommand = NULL;
        std::list<CCommand *>::iterator iter;
        for ( iter = m_Commands.begin(); iter != m_Commands.end(); iter ++ )
        {
                if ( !_stricmp( (*iter)->m_szCommand , const_cast<char *>(szCommand) ) )
                {
                        pCommand = (*iter);
                        if(pCommand)
                        {
                                pCommand->m_Function(const_cast<char *>(szParams));     
                                return true;
                        }
                }
        }
        return false;
}

// Coments

namespace Util
{
        void Quit(char *szParams)
        {
                ExitProcess ( 0 );
        }
}

void LoadRes(char *szParams)

{
        CLog::Printf("Charging resource named %s..", szParams);
        g_pServer->GetResourceManager()->Load(szParams);
}

void UnLoadRes(char *szParams)
{
    CLog::Printf("resource named%s..", szParams);;
        g_pServer->GetResourceManager()->Unload(szParams);
}

void ReStartRes(char *szParams)
{
        CLog::Printf("Please restart resourcer %s..", szParams);;
        g_pServer->GetResourceManager()->Restart(szParams);
}

void CCommandSystem::RegisterCommands()
{
        AddCommand("/q", Util::Quit);
        //
         AddCommand("/loadresource", LoadRes);
        AddCommand("/unloadresource", UnLoadRes);
        AddCommand("/restartresource", ReStartRes);
}

void CCommandSystem::UnregisterCommands()
{
        RemoveCommand("q");
         RemoveCommand("loadresource");
        RemoveCommand("unloadresource");
        RemoveCommand("restartresource");
}


        
