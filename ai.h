#ifndef AI_H
#define AI_H

#include <QObject>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <stdlib.h>
#include <time.h>

class AI : public QGraphicsPixmapItem
{

public:
    AI(int x=0,int y=0);
    int getX();
    int getY();
    int getIndex();
    bool isDizzy();
    bool isDead();
    QString getFaceDirection();
    void setX(int x);
    void setY(int y);
    void setDizzy(bool b);
    void turn();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void setPic(QString path);
    void getDizzy();
    void wakeUp();
    void die();

signals:

public slots:

private:
    int posX,posY;
    bool dizzy;
    bool dead;
    int index;
    QString faceDirection;

};

#endif // AI_H
