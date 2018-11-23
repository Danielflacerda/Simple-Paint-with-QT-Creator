#include "draft.h"
#include <QColorDialog>

draft::draft(QWidget *parent) : QWidget(parent)
{
}

void draft::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
    }
}
/*void draft::mouseMoveEvent(QMouseEvent *event)
{
     if (event->buttons() && Qt::LeftButton) {
         draw(event->pos());
     }
}*/

void draft::mouseReleaseEvent(QMouseEvent *event)
{
    draw(event->pos());
}


void draft::paintEvent(QPaintEvent *event)
{
    QPainter drawPicture(this);
    QRect rectangle;
    rectangle.setRect(0, 0, this->width()-1, this->height()-1);
    drawPicture.drawImage(rectangle, image, rectangle);
}

void draft::resizeEvent(QResizeEvent *event)
{
    QImage image2 (QSize(this->width(), this->height()), QImage::Format_RGB32);
    image2.fill(qRgb(0, 255, 255));
    QPainter painter (&image2);
    painter.drawImage(QPoint(0, 0), image);
    image = image2;
    update();
}

void draft::draw(QPoint point)
{

    QPainter painter(&image);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    //FAZER O IF E ELSE COM OS VALORES DA FUNCOES SET PRO DRAW
    if(girafa==0){
        painter.drawEllipse(QRect(lastPoint, point));
        update();
    }
    else if(girafa==1){
        painter.drawRect(QRect(lastPoint, point));
        update();
    }
    else if(girafa==2){
        painter.drawRoundedRect(QRect(lastPoint, point), 10, 10);
        update();
    }
    update();
}

void draft::setColorPen(QString rgb)
{
    QColor color = QColorDialog::getColor(Qt::yellow,this);
    pen.setColor(color);
}

void draft::setvariavelcircle()
{
    girafa = 0;
    qDebug()<<"girafa é 0";
}


void draft::setvariavelsquare()
{
    girafa = 1;
    qDebug()<<"girafa é 1";
}


void draft::setvariavelfashionsquare()
{
    girafa = 2;
    qDebug()<<"girafa é 2";
}

