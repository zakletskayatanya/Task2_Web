#include "web.h"

Web::Web(QObject *parent) : QObject { parent } {}

void Web::paintWebEvent(QPainter *painter, QPoint &cursorPosition_, int widthWidget_, int heightWidget_) {
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

    int centerRadius = 5;
    painter->drawEllipse(cursorPosition_, centerRadius, centerRadius);

    int pieceWidget = 4;

    QPolygon poligon;
    QPolygon poligonLeft;
    QPolygon poligonRight;
    QPolygon poligonTop;
    QPolygon poligonBottom;

    for (int j = 0; j <= pieceWidget; ++j) {
        painter->drawLine(0, heightWidget_ - heightWidget_ * j / pieceWidget, cursorPosition_.x(), cursorPosition_.y());

        painter->drawLine(widthWidget_ * j / pieceWidget, 0, cursorPosition_.x(), cursorPosition_.y());

        painter->drawLine(widthWidget_, heightWidget_ * j / pieceWidget, cursorPosition_.x(), cursorPosition_.y());

        painter->drawLine(widthWidget_ - widthWidget_ * j / pieceWidget, heightWidget_, cursorPosition_.x(), cursorPosition_.y());

        poligonLeft << QPoint((0 + cursorPosition_.x()) / 2, (heightWidget_ - heightWidget_ * j / pieceWidget + cursorPosition_.y()) / 2);
        poligonTop << QPoint((widthWidget_ * j / pieceWidget + cursorPosition_.x()) / 2, (0 + cursorPosition_.y()) / 2);
        poligonRight << QPoint((widthWidget_ + cursorPosition_.x()) / 2, (heightWidget_ * j / pieceWidget + cursorPosition_.y()) / 2);
        poligonBottom << QPoint((widthWidget_ - widthWidget_ * j / pieceWidget + cursorPosition_.x()) / 2, (heightWidget_ + cursorPosition_.y()) / 2);
    }

    poligon << poligonLeft << poligonTop << poligonRight << poligonBottom;

    painter->drawPolygon(poligon);
}
