#ifndef DRAFT_H
#define DRAFT_H

#include <QDebug>
#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QPaintEvent>
#include <QStringList>

class draft : public QWidget
{

    Q_OBJECT
public:
    explicit draft(QWidget *parent = nullptr);
    QPoint point;
    QPoint lastPoint;
    int girafa;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    //void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
public slots:
    void draw (QPoint point);
    void setColorPen (QString rgb);
    void setvariavelsquare();
    void setvariavelcircle();
    void setvariavelfashionsquare();

private:
    QImage image;
    QPen pen;


};

#endif // DRAFT_H
