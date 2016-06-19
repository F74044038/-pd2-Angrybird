#include <obstacle.h>
#include    <iostream>
Obstacle::Obstacle(float x, float y, float w,float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    life=3;
    role="obstacle";
    control=false;
    //set image
    g_pixmap.setPixmap(pixmap);
    /*std::cout<<pixmap.width()<<std::endl;
   std::cout<<pixmap.height()<<std::endl;
    std::cout<<g_pixmap.boundingRect().width()<<std::endl;
   std::cout<<g_pixmap.boundingRect().height()<<std::endl;*/
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSizeF(w,h);

    // create body
    b2BodyDef bodydef;
    bodydef.type=b2_dynamicBody;
    bodydef.bullet=true;
    bodydef.position.Set(x,y);
    bodydef.userData=this;
    g_body=world->CreateBody(&bodydef);
    b2PolygonShape bodyobstacle;
    bodyobstacle.SetAsBox(w/2,h/2);
    b2FixtureDef fixturedef;
    fixturedef.shape=&bodyobstacle;
    fixturedef.density=obstacle_d;
    fixturedef.friction=obstacle_f;
    fixturedef.restitution=obstacle_r;
    g_body->CreateFixture(&fixturedef);

    // bulid timer
    connect(timer,SIGNAL(timeout()),this,SLOT(paint()));
    scene->addItem(&g_pixmap);
}

void Obstacle::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}
