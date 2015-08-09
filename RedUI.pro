#-------------------------------------------------
#
# Project created by QtCreator 2015-08-07T23:04:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RedUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

DISTFILES += \
    UIForm.ui.qml \
    UI.qml

RESOURCES += \
    systray.qrc
