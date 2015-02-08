/
 * Solution   : Euro Truck Multiplayer RBR
 * Project    : Euro Truck Multiplayer RBR - Server
 * Licence    : GNU GPL v2
 * File       : CConfig.cpp
 * System Save xml:
 * Description: Project By RBR Team
 * Dev Sun : 
 *Site :BlackBox.ac  <carlos_sk8ever_@hotmail.com>>
 *
 */
 
 #include "StdInc.h"

//CServer

CConfig::CConfig(CString szConfigFileName)
{
        m_node = NULL;
        m_bInitialized = false;
        m_szConfigFileName.Set(szConfigFileName.Get());

        if(m_document.LoadFile(m_szConfigFileName.Get()))
        {
                m_document.SetTabSize(4);
                m_node = m_document.RootElement();
                m_bInitialized = true;
        }
        
        {
        //save();
        //SAFE_DELETE;
}
CString CConfig::Get(CString szNodeName)
{
        if(!m_bInitialized) 
        {
                return NULL;
        }

        CString strValue;

        m_node = m_document.RootElement();
        if(m_node && m_node->FirstChild(szNodeName.Get()) != 0)
        {
                m_node = m_node->FirstChild(szNodeName.Get())->ToElement();
                if ( m_node && m_node->Type() != TiXmlNode::COMMENT )
                {
                        strValue.Set ( m_node->GetText ( ) );
                        return strValue;
                }
        }
        return NULL;
}
}

CConfig::~CConfig()
