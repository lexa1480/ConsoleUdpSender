#include <QCoreApplication>
#include "UdpServer.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ip_st_x::CStPlugMain m_plugIpSt;
    ip_st_x::CStPlugClient m_plugClient;

    try
    {
        if(!m_plugIpSt.Load())
        {
            throw "Load";
        }
        m_plugIpSt.SetAppName("StTestApp");
//        m_plugIpSt.SetSockMcAddr( "234.0.1.0" );
        if(!m_plugIpSt.Start())
        {
            throw "Start";
        }
        if(!m_plugIpSt.GetStClient(m_plugClient))
        {
            throw "Get Client";
        }
        m_plugClient.SetClientName("TestStPlugin");
        if(!m_plugClient.AssignSource("NmeaTime", ip_st_x::ST_WRITER))
        {
            throw "Assign Source";
        }
        if(!m_plugClient.OpenStClient())
        {
            throw "Open Client";
        }
        UdpServer server(m_plugIpSt, m_plugClient);
        a.exec();

    }
    catch (char const* str)
    {
        std::cout << "Error: " << str << std::endl;
    }

    return 1;
}
