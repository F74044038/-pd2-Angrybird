#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define obstacle_d 15.0f
#define obstacle_f 0.8f
#define obstacle_r 0.5f

class Obstacle:public GameItem
{
    public:
        Obstacle(float x, float y, float w,float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
        void setLinearVelocity(b2Vec2 velocity);
               int life;
};

#endif // OBSTACLE_H
