#include "mainwindow.h"

#include <QApplication>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
//#include <QPaintEvent>
#include <QPainter>
#include <QLabel>
#include <QWidget>

class particles : public QWidget{
    Q_OBJECT
public:

    particles();
    virtual ~particles() {};

public slots:
    void make();
    void setc(int value);
    void setr(int value);
signals:

private:
    int row;
    int column;
    QLabel *text;
    QGridLayout *layout;
    QWidget *newwindow;

};

particles::particles():row(0), column(0){

    text->setText("Welcome to Particles on a Board!");
    layout->addWidget(text, 0, 0, 1, -1);
    newwindow->setWindowTitle("Particles on a Board");
    newwindow->setLayout(layout);
}


void particles::setr(int value){
    row = value;
}

void particles::setc(int value){
    column = value;
}




void particles::make(){//QPaintEvent *e
    /*QPainter painter(window);
    painter.setBrush(QBrush(Qt::blue) );
    double width = 20;
    double width = 20.0, height = 20.0;
    double x_coordinate =10.0, y_coordinate = 10.0;
    QRectF rectangle(x, y, width, height);
    painter.drawRect(rectangle);*/
    newwindow->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    QSpinBox *sp1 = new QSpinBox;
    QSpinBox *sp2 = new QSpinBox;
    QPushButton* button = new QPushButton("Generate Particles");
    sp1->setRange(1,20);
    sp2->setRange(1,20);
    QHBoxLayout *layout1 = new QHBoxLayout;

    layout1->addWidget(sp1);
    layout1->addWidget(sp2);

    QVBoxLayout *layout2 = new QVBoxLayout;
    layout2->addLayout(layout1);
    layout2->addWidget(button);


    QWidget *window = new QWidget;
    window->setLayout(layout2);
    window->show();
    window->showMaximized();

    particles p_window;

    QObject::connect(sp1, SIGNAL(valueChanged(int)) , &p_window, SLOT(setr(int)));
    QObject::connect(sp2, SIGNAL(valueChanged(int)) , &p_window, SLOT(setc(int)));
    QObject::connect(button, SIGNAL(clicked()), &p_window, SLOT(make()));

    return a.exec();
}
