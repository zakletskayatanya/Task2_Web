#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QCursor>
#include "web.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void moveEventInWidget(QRectF treshold, QPoint &point, QPoint &centerWidgetPoint);

private:
    Ui::Widget *ui;

    int widthWidget_;
    int heightWidget_;
    QPoint cursorPosition_;
    QPoint centerWidgetPoint_;
    bool mouseLeftButtonPress_ = false;
    QCursor cursorArrow;
    QCursor cursorCross;
    QRectF tresholdWidget;
};

#endif // WIDGET_H
