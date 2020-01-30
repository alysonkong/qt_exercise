#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QSpinBox>
#include <QPushButton>
//#include <QGridLayout>
#include <QHBoxLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QLabel>
#include <QWidget>



class particles : public QWidget{
    Q_OBJECT
public:
    particles();
   //
   //virtual ~particles() {};

public slots:
    void make();
    void setc(int value);
    void setr(int value);
    void columnnumbers();

private:
    int row;
    int column;
    QLabel *text;
    QGridLayout *layout;

 protected:
    void closeEvent(QCloseEvent* e) override;

};

class oneparticle : public QWidget{
      Q_OBJECT
 public:
    oneparticle();
    QSize minimumSizeHint() const override;

 public slots:
    void paintEvent(QPaintEvent *) override;



};

#endif // MAINWINDOW_H
