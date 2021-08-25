QT -= gui
QT += network
QT += core

CONFIG += c++98 console
CONFIG -= app_bundle

LIBS += -ldl

SOURCES += \
        UdpServer.cpp \
        main.cpp

HEADERS += \
    UdpServer.h \
    nmea/nmea_packet.h \
    nmea/nmea_zda.h \
    nmea/t_nmea.h

TARGET = $${TARGET}.bin
