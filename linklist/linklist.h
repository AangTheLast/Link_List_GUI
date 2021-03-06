#ifndef LINKLIST_H
#define LINKLIST_H

#include <QMainWindow>
#include <QPainter>
//Auto generated by QT
QT_BEGIN_NAMESPACE
namespace Ui { class linklist; }
QT_END_NAMESPACE

class linklist : public QMainWindow
{
    Q_OBJECT

public:
    linklist(QWidget *parent = nullptr);
    linklist(QObject *parent);
    ~linklist();
    virtual void paintEvent(QPaintEvent *event);
    virtual void paint(QPaintEvent *event);
private:
    Ui::linklist *ui;
private slots:
    void GetValue();
    void updated();
    void Pop();
    void Push();

};

#endif // LINKLIST_H
