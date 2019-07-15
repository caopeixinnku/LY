#include "ai.h"


AI::AI(int x,int y)
{
    srand((unsigned) time(NULL));
    this->index = rand() % 4;
    this->setPixmap (QPixmap(":/mud/pic/mud_zheng_a.png"));
    this->posX = x;
    this->posY = y;
    this->dizzy = false;
    this->faceDirection = "front";
    this->dead = false;
}

int AI::getX()
{
    return this->posX;
}

int AI::getY()
{
    return this->posY;
}

int AI::getIndex()
{
    return this->index;
}

bool AI::isDizzy()
{
    return this->dizzy;
}

bool AI::isDead()
{
    return this->dead;
}

QString AI::getFaceDirection()
{
    return this->faceDirection;
}

void AI::setX(int x)
{
    this->posX = x;
}

void AI::setY(int y)
{
    this->posY = y;
}

void AI::setDizzy(bool b)
{
    this->dizzy = b;
}

void AI::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}

void AI::turn()
{
    index = rand() % 4;
    switch (this->index) {
    case 0:
        this->faceDirection = "back";
        this->setPic(":/mud/pic/mud_fan_a.png");
        break;
    case 1:
        this->faceDirection = "left";
        this->setPic(":/mud/pic/mud_left_a.png");
        break;
    case 2:
        this->faceDirection = "front";
        this->setPic(":/mud/pic/mud_zheng_a.png");
        break;
    case 3:
        this->faceDirection = "right";
        this->setPic(":/mud/pic/mud_right_a.png");
        break;
    }
}

void AI::moveUp()
{
    if(this->posY <= 0) {
        this->index = rand() % 4;
        this->turn();
        return;
    }
    else {
        this->moveBy(0,-40);
        this->posY--;
    }
}

void AI::moveLeft()
{
    if(this->posX <= 0) {
        this->index = rand() % 4;
        this->turn();
        return;
    }
    else {
        this->moveBy(-40,0);
        this->posX--;
    }
}

void AI::moveDown()
{
    if(this->posY >= 14) {
        this->index = rand() % 4;
        this->turn();
        return;
    }
    else {
        this->moveBy(0,40);
        this->posY++;
    }
}

void AI::moveRight()
{
    if(this->posX >= 14) {
        this->index = rand() % 4;
        this->turn();
        return;
    }
    else {
        this->moveBy(40,0);
        this->posX++;
    }
}

void AI::getDizzy()
{
    this->dizzy = true;
    if(this->faceDirection == "back") this->setPic(":/mud/pic/mud_yun_fan_a.png");
    if(this->faceDirection == "left") this->setPic(":/mud/pic/mud_yun_left_a.png");
    if(this->faceDirection == "front") this->setPic(":/mud/pic/mud_yun_zheng_a.png");
    if(this->faceDirection == "right") this->setPic(":/mud/pic/mud_yun_right_a.png");
}

void AI::wakeUp()
{
    this->dizzy = false;
    if(this->faceDirection == "back") this->setPic(":/mud/pic/mud_fan_a.png");
    if(this->faceDirection == "left") this->setPic(":/mud/pic/mud_left_a.png");
    if(this->faceDirection == "front") this->setPic(":/mud/pic/mud_zheng_a.png");
    if(this->faceDirection == "right") this->setPic(":/mud/pic/mud_right_a.png");
}

void AI::die()
{
    this->setPic(":/bg/pic/floor.png");
    this->dead = true;
}
