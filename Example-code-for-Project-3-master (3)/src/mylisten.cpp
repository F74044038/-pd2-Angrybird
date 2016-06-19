#include<mylisten.h>
void mylisten::BeginContact(b2Contact *contact)
{

    b2Fixture*a=contact->GetFixtureA();
    b2Fixture*b=contact->GetFixtureB();
    if(static_cast<GameItem*>(a->GetBody()->GetUserData())->role=="bird"){
        if(static_cast<GameItem*>(b->GetBody()->GetUserData())->role=="obstacle"){
            std::cout<<"listen a obstalce"<<std::endl;
           -- static_cast<Obstacle*>(b->GetBody()->GetUserData())->life;

        }
        else if(static_cast<GameItem*>(b->GetBody()->GetUserData())->role=="pig"){
                  -- static_cast<pig*>(b->GetBody()->GetUserData())->life;
              std::cout<<"listen a pig"<<std::endl;
        }
    }

    if(static_cast<GameItem*>(b->GetBody()->GetUserData())->role=="bird"){
        if(static_cast<GameItem*>(a->GetBody()->GetUserData())->role=="obstacle"){
            std::cout<<"listen b obstalce"<<std::endl;
           -- static_cast<Obstacle*>(a->GetBody()->GetUserData())->life;}

        else if(static_cast<GameItem*>(a->GetBody()->GetUserData())->role=="pig"){
             -- static_cast<pig*>(a->GetBody()->GetUserData())->life;
              std::cout<<"listen b pig"<<std::endl;
        }
    }
}
