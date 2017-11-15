#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Big Numbers Power");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        Dodecahedron::Bigint pow = baseNumber;
        pow.pow(arg1.toLongLong());
        ui->lcdNumber_3->setDigitCount(25);
        ui->lcdNumber_3->display(Dodecahedron::to_string(pow).c_str());
        ui->lcdNumber->display(QString::number(pow.digits()));
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        if(arg1 != "0")
        baseNumber = arg1.toLongLong();
    }
}
