#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QFile>
#include<QPushButton>
#include<hostnamedialog.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    int en;
    int boy;
    QLabel *hostnamelabel;
};

#endif // MAINWINDOW_H
