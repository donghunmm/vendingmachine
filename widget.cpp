#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    money = 0;
    updateButtons();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff) {
    money += diff;

    if (diff > 0) {
        hasInsertedMoney = true;
    }

    ui->lcdNumber->display(money);
    updateButtons();
}

void Widget::updateButtons(){
    ui->pcCoffee->setEnabled(money >= 100);
    ui->pcTea->setEnabled(money >= 150);
    ui->pcMilk->setEnabled(money >= 200);
    ui->pbReset->setEnabled(hasInsertedMoney && money > 0);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pcCoffee_clicked()
{
    if(money >= 100){
        changeMoney(-100);
    }

}

void Widget::on_pcTea_clicked()
{
    if(money >= 150){
        changeMoney(-150);
    }
}
void Widget::on_pcMilk_clicked()
{
    if(money >= 200){
        changeMoney(-200);
    }
}

void Widget::on_pbReset_clicked()
{

    int C500 = money / 500;
    money %= 500;
    int C100 = money / 100;
    money %= 100;
    int C50 = money / 50;
    money %= 50;
    int C10 = money / 10;
    money %= 10;
    QString msg = QString("500원 : %1개 , 100원 : %2개 , 50원 : %3개, 10원 : %4개").arg(C500).arg(C100).arg(C50).arg(C10);

    QMessageBox nb;
    nb.information(nullptr,"Change",msg);
}







