#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QPushButton>
#include<ActiveQt\QAxWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual QSize sizeHint () const;

    ~MainWindow();

private slots:
    void openProcess();
    void OpenIE();
    void OpenFolder();
    void OpenExcel();
    void readResult(int exitCode);
private:
    QProcess *p;
    QProcess *p1;
    QProcess *p2;
    QProcess *p3;

};

#endif // MAINWINDOW_H
