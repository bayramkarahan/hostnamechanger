#-------------------------------------------------
#
# Project created by QtCreator 2022-05-23T20:45:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hostnamechanger
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    hostnamedialog.cpp \
        mainwindow.cpp \
    main.cpp

HEADERS += \
        hostnamedialog.h \
        mainwindow.h

FORMS +=

target.path = /usr/bin

desktop_file.files = hostnamechanger.desktop
desktop_file.path = /usr/share/applications/

icon.files = icons/hostname.svg
icon.path = /usr/share/icons

INSTALLS += target desktop_file icon
DISTFILES += \
       hostnamechanger.desktop\


RESOURCES += \
    resource.qrc
