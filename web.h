#ifndef WEB_H
#define WEB_H

#include <QObject>
#include <QPainter>

class Web : public QObject {
  Q_OBJECT
 public:
  explicit Web(QObject *parent = nullptr);

    public:
    void paintWebEvent(QPainter *painter, QPoint &cursorPosition_, int widthWidget_, int heightWidget_);

 signals:
};

#endif  // WEB_H
