#include "UdpServer.h"
#include <QTimer>
#include <QTime>
#include "nmea/nmea_zda.h"

UdpServer::UdpServer(ip_st_x::CStPlugMain &m_plugIpSt, ip_st_x::CStPlugClient &m_plugClient, QObject* pwgt) : QObject(pwgt){

    this->m_plugClient = m_plugClient;
    this->m_plugIpSt = m_plugIpSt;
    QTimer* ptimer = new QTimer();
    ptimer->setInterval(1000);
    ptimer->start();

    connect(ptimer, SIGNAL(timeout()), SLOT(slotSendData()));
}

void UdpServer::slotSendData(){

    QTime time = QTime::currentTime();
    std::string sTime = (time.toString("hhmmss.zzz")).toStdString();
    std::string sResult = "$GLZDA," + sTime;
    std::cout << "String: " << sResult << std::endl;
    nmea::CNmeaPacket packet(sResult);   

    std::string sPacket = packet.GetString();
    std::cout << "Packet: " << sPacket << std::endl;

    NByte* pPacket = (NByte*)sPacket.c_str();
    NDword dwSize = sPacket.size();
    m_plugClient.Write( pPacket, dwSize );
}

UdpServer::~UdpServer(){
        m_plugClient.CloseStClient();
        m_plugIpSt.Stop();
        m_plugIpSt.Free();
}
