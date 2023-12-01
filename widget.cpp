#include "widget.h"
#include "ui_widget.h"
#include "web.h"

#include <QMouseEvent>
#include <QCursor>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    widthWidget_ = this->width();
    heightWidget_ = this->height();

    cursorArrow = QCursor(Qt::ArrowCursor);
    cursorCross = QCursor(Qt::CrossCursor);

    centerWidgetPoint_ = QPoint(widthWidget_ / 2, heightWidget_ / 2);

    tresholdWidget = QRectF(0, 0, widthWidget_, heightWidget_);
}

Widget::~Widget() { delete ui; }

void Widget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    Web *web = new Web;
    if (mouseLeftButtonPress_ == true)
        web->paintWebEvent(&painter, cursorPosition_, widthWidget_, heightWidget_);
}

void Widget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        cursorPosition_ = event->pos();
        mouseLeftButtonPress_ = true;
        this->setCursor(cursorCross);

        repaint();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event) {

    if (mouseLeftButtonPress_ == true) {
        cursorPosition_ = event->pos();
        this->setCursor(cursorCross);

        repaint();

        this->moveEventInWidget(tresholdWidget, cursorPosition_, centerWidgetPoint_);
    }
}


void Widget::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    this->setCursor(cursorArrow);
    mouseLeftButtonPress_ = false;
}

void Widget::moveEventInWidget(QRectF treshold, QPoint &point, QPoint &centerWidgetPoint)
{
    if (treshold.contains(point) == false)
        QCursor::setPos(mapToGlobal(centerWidgetPoint));
}
