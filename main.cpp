#include "mainwindow.h"
//look into minimumSize for QWidget
//QGridLayout::addWidget(widget, row, column, alignment
//create a single widget and paint all the particles
//setsize of the window

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
    //window->showMaximized();

    particles p_window;


   QObject::connect(sp1, SIGNAL(valueChanged(int)) , &p_window, SLOT(setr(int)));
    QObject::connect(sp2, SIGNAL(valueChanged(int)) , &p_window, SLOT(setc(int)));
    QObject::connect(button, SIGNAL(clicked()), &p_window, SLOT(make()));
    QObject::connect(button, SIGNAL(clicked()), &p_window, SLOT(columnnumbers()));


    return a.exec();
}
