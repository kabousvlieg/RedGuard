#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QComboBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Background image
    QPixmap pix("C:/Kobus/werk/RedUI/images/worldmap_notdone.png");
    //QPixmap scaled = pix.scaled(QSize(1000, 1000));
    ui->backround_image->setPixmap(pix);    //TODO scaling with app

    //System tray
    createIconGroupBox();
    createMessageGroupBox();
    createActions();
    createTrayIcon();
    trayIcon->show();
    showMessage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createIconGroupBox()
{
    iconLabel = new QLabel("Icon:");
    iconComboBox = new QComboBox;
    iconComboBox->addItem(QIcon(":/images/bad.png"), tr("Bad"));
    iconComboBox->addItem(QIcon(":/images/heart.png"), tr("Heart"));
    iconComboBox->addItem(QIcon(":/images/trash.png"), tr("Trash"));
}

void MainWindow::createActions()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void MainWindow::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
//    trayIconMenu->addAction(minimizeAction);
//    trayIconMenu->addAction(maximizeAction);
//    trayIconMenu->addAction(restoreAction);
//    trayIconMenu->addSeparator();
//    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}

void MainWindow::showMessage()
{
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(
        typeComboBox->itemData(typeComboBox->currentIndex()).toInt());
    trayIcon->showMessage("Hallo", "Hallo daar", icon,
                          10 * 1000);
}

void MainWindow::createMessageGroupBox()
{
    typeComboBox = new QComboBox;
    typeComboBox->addItem(tr("None"), QSystemTrayIcon::NoIcon);
    typeComboBox->addItem(style()->standardIcon(
         QStyle::SP_MessageBoxInformation), tr("Information"),
         QSystemTrayIcon::Information);
    typeComboBox->addItem(style()->standardIcon(
         QStyle::SP_MessageBoxWarning), tr("Warning"),
         QSystemTrayIcon::Warning);
    typeComboBox->addItem(style()->standardIcon(
         QStyle::SP_MessageBoxCritical), tr("Critical"),
         QSystemTrayIcon::Critical);
    typeComboBox->setCurrentIndex(1);
}
