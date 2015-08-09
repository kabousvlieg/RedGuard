#include <QApplication>
#include <QMessageBox>
#include <qsystemtrayicon.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(systray);
    QApplication a(argc, argv);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0,
                              QObject::tr("Systray"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
        return 1;
    }

    MainWindow mw;
    mw.show();

    return a.exec();
}


/*
 * TODO lysie
 *  - Teken wereldkaart
 *  - Teken voorbeel traffic pyl
 *  - Toets popup
 *  - Monitor traffic
 *  - Implement unit testing framework
 *  - Skep private github repo
 *  - Commit die kode na github
 *  - Nooi RK en CL uit na die github repo
 *  - Koppel met IP geolocation service (Maxmind's free GeoIP database?)
 */

