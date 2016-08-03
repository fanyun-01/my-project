#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QLabel>
//#include <QAxWidget>
#include<ActiveQt\QAxWidget>

QSize MainWindow::sizeHint() const
{
     return QSize( 320, 80 );
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    p =new QProcess(this);
    QPushButton *bt = new QPushButton("OpenFile", this);
    bt->setGeometry(0,0,80,80);
    connect(bt,SIGNAL(clicked()),this,SLOT(openProcess()));

    p1 =new QProcess(this);
    QPushButton *bt1 = new QPushButton("OpenWeb", this);
    bt1->setGeometry(80,0,80,80);
    connect(bt1,SIGNAL(clicked()),this,SLOT(OpenIE()));

    p2 =new QProcess(this);
    QPushButton *bt2 = new QPushButton("OpenFd", this);
    bt2->setGeometry(160,0,80,80);
    connect(bt2,SIGNAL(clicked()),this,SLOT(OpenFolder()));


    p3 =new QProcess(this);
    QPushButton *bt3 = new QPushButton("OpenExcel", this);
    bt3->setGeometry(240,0,80,80);
    connect(bt3,SIGNAL(clicked()),this,SLOT(OpenExcel()));
}

MainWindow::~MainWindow()
{

}
/*打开txt*/
void MainWindow::openProcess()
{
   QProcess* process = new QProcess();
   QString notepadPath = "notepad.exe E:\\Test\\Test.txt";
   process->start(notepadPath);
}

/*打开WEB网页*/
void MainWindow::OpenIE()
{
    // 方法一
    QProcess* process = new QProcess();
    QDesktopServices::openUrl(QUrl(QString("www.baidu.com")));
}

//打开文件夹
void MainWindow::OpenFolder()
{
     QProcess::execute("explorer E:\\Test");
}
/*创建打开excel*/
void MainWindow::OpenExcel()
{

    QProcess::execute("explorer E:\\Test\\Test.xlsx");
}

void MainWindow::readResult(int exitCode)
{
    if(exitCode == 0) {
        QTextCodec* gbkCodec = QTextCodec::codecForName("GBK");
        QString result = gbkCodec->toUnicode(p->readAll());
        QMessageBox::information(this, "dir", result);
    }
}


