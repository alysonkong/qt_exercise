#include "mainwindow.h"
#include "ui_mainwindow.h"


particles::particles():row(1), column(1){
    text = new QLabel("Welcome to Particles on a Board!");
    layout = new QGridLayout;
    layout->addWidget(text, 0, 0, 1, -1);
    setWindowTitle("Particles on a Board");
}


void particles::setr(int value){
    row = value;
}

void particles::setc(int value){
    column = value;

}


/**
 * @brief particles::make() adds certain number of particles into the grid layout via for loop
 */
void particles::make(){

      text->setText(QString::fromStdString("row is " + std::to_string(row)+ " column is " + std::to_string(column)));
      //layout->setColumnStretch(column, 0);
      //layout->setRowStretch(row+4,0);
     // setFixedSize(400,400);
      for(auto i = 0; i <row; ++i){
          for(auto n= 0; n<column; ++n){
              oneparticle *one = new oneparticle;
              layout->addWidget(one, i+1, n); //Qt::AlignCenter
          }
      }
    setLayout(layout);
    show();


    return;

}

void particles::columnnumbers(){
    for(auto n= 0; n<column; ++n){
        QLabel *colnum = new QLabel(QString::fromStdString(std::to_string(((column/2)-column) + n+1)));
        layout->addWidget(colnum, row+2, n, 1, 1);
    }
}

void particles::closeEvent(QCloseEvent* e){
    exit(0);
}


oneparticle::oneparticle(){}



QSize oneparticle::minimumSizeHint() const{
    //return minimumSize();
    return QSize(15,15);
}

/**
 * @brief oneparticle::paintEvent overrides oneparticle class. draw into this widget object
 * @param e
 */
void oneparticle::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::blue));
    QRectF rectangle(0, 0, 20, 20);
    painter.drawRect(rectangle);


}
