#include "mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QScreen>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QToolButton>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Ekran boyutunu al
    QSize screenSize = qApp->screens()[0]->size();
    boy = screenSize.height() / 153.6;
    en  = boy * 1.1;

    // Pencere boyutu ayarla
    this->setFixedSize(boy * 70, en * 37);

    // Ortala
    int x = (screenSize.width() - this->width()) / 2;
    int y = (screenSize.height() - this->height()) / 2;
    this->move(x, y);

    this->setWindowIcon(QIcon(":/icons/hostname.svg"));
    this->setWindowTitle("Hostname Değiştirici");
    int baseFont = boy * 2;

    // Hostname Label
    hostnamelabel = new QLabel(this);
    hostnamelabel->setFont(QFont("Arial", baseFont + 5, QFont::Bold));
    hostnamelabel->setAlignment(Qt::AlignCenter);
    hostnamelabel->setFixedHeight(boy * 10);

    // Hostname oku
    QFile file("/etc/hostname");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString current = QString::fromUtf8(file.readAll()).trimmed();
        hostnamelabel->setText("Bilgisayar Adı: " + current);
        file.close();
    }

    // Hostname değiştir butonu
    QToolButton *hostnameChangeButton = new QToolButton(this);
    hostnameChangeButton->setFixedSize(QSize(boy * 30, boy * 10));
    hostnameChangeButton->setIcon(QIcon(":/icons/hostname.svg"));
    hostnameChangeButton->setIconSize(QSize(boy * 5, boy * 5));
    hostnameChangeButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    hostnameChangeButton->setText("Hostname Değiştir");
    hostnameChangeButton->setFont(QFont("Arial", baseFont, QFont::Normal));

    connect(hostnameChangeButton, &QToolButton::clicked, [=]() {
        HostnameDialog dlg(boy * 50, boy * 20);
        if (dlg.exec() == QDialog::Accepted) {

            QFile f2("/etc/hostname");
            if (f2.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QString current = QString::fromUtf8(f2.readAll()).trimmed();
                hostnamelabel->setText("Bilgisayar Adı: " + current);
                f2.close();
            }
        }
    });

    //
    // ✔ Responsive Layout
    //
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->setContentsMargins(20, 20, 20, 20);
    vbox->setSpacing(boy * 3);

    vbox->addStretch();
    vbox->addWidget(hostnamelabel, 0, Qt::AlignCenter);
    vbox->addWidget(hostnameChangeButton, 0, Qt::AlignCenter);
    vbox->addStretch();

    QWidget *central = new QWidget(this);
    central->setLayout(vbox);
    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
}
