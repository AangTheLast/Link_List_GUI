#include "linklist.h"
#include "ui_linklist.h"
#include <QCoreApplication>
#include <QLinkedList>
#include <QDebug>
#include <QString>
#include "QMessageBox"
#include "math.h"
#include<string.h>
#include<QVector>
int a=0;
int b=0;
int k;
bool temp=false;
bool m_flag=false;
bool n_flag=false;
QVector<QString> aang;
linklist::linklist(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::linklist)
{
    ui->setupUi(this);
    //Connect Push Button
    connect(ui->push, SIGNAL(released()), this, SLOT(Push()));
    //Connect Pop Button
    connect(ui->pop, SIGNAL(released()), this, SLOT(Pop()));
}
linklist::linklist(QObject *parent)
{
    m_flag=false;
}
linklist::~linklist()
{
    delete ui;
}

void linklist::GetValue()
{
    QString displayVal = ui->Display->text();
}

void linklist::updated()
{
    temp=true;
    //update();
}


//void linklist::Push(){
void linklist::paintEvent(QPaintEvent *event)
{

    if(aang.size()==1)
    {
        QPainter painter(this);
        QPainter line(this);
        QPainter text(this);
        QPen pen;
        pen.setColor(Qt::green);
        pen.setStyle(Qt::SolidLine);
        pen.setWidth(3);
        pen.setBrush(Qt::green);
        pen.setCapStyle(Qt::RoundCap);
        pen.setJoinStyle(Qt::RoundJoin);

        painter.setPen(pen);
        painter.drawRect(QRect(30,400,200,100));
        line.drawLine(100,400,100,500);
        text.setFont(QFont("Times", 16, QFont::Bold));
        text.drawText(QPoint(30,400),"Value");
        text.drawText(QPoint(135,400),"Address");
        text.drawText(QPoint(50,450),"Null");
        //220 ka diffreenece
    }
    else if(aang.size()>1)
    {
        int i,k=30;
        for(i=0;i<aang.size();k+=220,i++)
       {
            QPainter rec2(this);
            QPainter l2(this);
            QPainter text(this);
            QPainter arrow(this);
            QPen pen;
            pen.setColor(Qt::green);
            pen.setStyle(Qt::SolidLine);
            pen.setWidth(3);
            pen.setBrush(Qt::green);
            pen.setCapStyle(Qt::RoundCap);
            pen.setJoinStyle(Qt::RoundJoin);

            rec2.drawRect(QRect(k,400,200,100));
            l2.drawLine(k+70,400,k+70,500);
            arrow.setFont(QFont("Time",20,QFont::Bold));
            arrow.drawText(QPoint(k+200,450),"->");

            text.setFont(QFont("Times", 16, QFont::Bold));
            text.drawText(QPoint(k,400),"Value");
            text.drawText(QPoint(k+105,400),"Address");

       }
        int r;
        for(i=0,r=30;i<aang.size();r+=220,i++)
        {
            //int a[100];
            //a[i]=(int)&aang[i];
        QPainter t2(this);
        t2.setFont(QFont("Times", 16, QFont::Bold));
        t2.drawText(QPoint(r-200,450),aang[i]);
        //t2.drawText(QPoint(r+100,450),&a[i]);

        }
    }
}



void linklist::paint(QPaintEvent *event)
{
    if(n_flag)
     {
        int j,k=30;
        for(j=aang.size();j>=0;k+=220,j--)
         {
          QPainter rec3(this);
          QPainter l3(this);
          QPen pen;
          pen.setColor(Qt::green);
          pen.setStyle(Qt::SolidLine);
          pen.setWidth(3);
          pen.setBrush(Qt::green);
          pen.setCapStyle(Qt::RoundCap);
          pen.setJoinStyle(Qt::RoundJoin);
          rec3.drawRect(QRect(k,400,200,100));
          l3.drawLine(k+40,400,k+40,500);
          n_flag=false;
        }
      }
}


void linklist::Push()
{
    m_flag=true;
    update();
    QString v =ui->Display->text();
    aang.append(v);
    a++;

}

void linklist::Pop()
{
    update();
    n_flag=true;
    aang.pop_back();
    if(aang.size()<=0)
    {
        QMessageBox::about(this," ","Nothing Remains To Pop");
    }

}

//}
