#ifndef SERVERUDP_H
#define SERVERUDP_H

#include <QObject>
#include <iostream>
#include <ip_st_x3.h>

class UdpServer : public QObject
{
    Q_OBJECT

private:
    ip_st_x::CStPlugMain m_plugIpSt;
    ip_st_x::CStPlugClient m_plugClient;

public:
    UdpServer(ip_st_x::CStPlugMain &m_plugIpSt, ip_st_x::CStPlugClient &m_plugClient, QObject* pwgt = 0);
    ~UdpServer();

public slots:
    void slotSendData();

};
#endif // SERVERUDP_H
