#include <Box2D/Box2D.h>
#include <vector>
using namespace std;

class Magnetic_object                           //create magnetic object at a position x,y
{ public:
    int power;                                    //magnetic effect 
   

    b2Body* body;
    b2CircleShape circle;
    b2FixtureDef ballfd;
    b2BodyDef ballbd; 
    Magnetic_object(float32 x,float32 y,b2World* m_world)
    {
            
            circle.m_radius = 2.0;

                                                    //creating fixture 
            ballfd.shape = &circle;
            ballfd.density = 1.0f;
            ballfd.friction = 0.0f;
            ballfd.restitution = 0.1f;

                                                    //definition for left static circle
            ballbd.type = b2_staticBody;
            ballbd.position.Set(x,y);
            body = m_world->CreateBody(&ballbd);
            body->CreateFixture(&ballfd);

            power=1;                                //attractive in the beginning
    }
      void change_nature()
      {
        power=power*-1;
      }

}; 


class Non_magnetic_object                           //non-magnetic objects class 
{
    public:
      b2Body* body;
      b2CircleShape circle;
      b2BodyDef ballbd;
      b2FixtureDef ballfd;
      Non_magnetic_object(float32 x,float32 y,b2World* m_world)  //create non-magnetic object
      {
        
        circle.m_radius = 1.0;

                                                //creating fixture 
        ballfd.shape = &circle;
        ballfd.density = 1.0f;
        ballfd.friction = 0.0f;
        ballfd.restitution = 0.5f;

                                                //ball1 movingdown
        ballbd.type = b2_dynamicBody;
        ballbd.position.Set(x,y);
        body = m_world->CreateBody(&ballbd);
        body->CreateFixture(&ballfd);
      }
};

extern vector<Magnetic_object*> Magnetic_object_list;       //pointers of magnetic material in world 
extern vector<Non_magnetic_object*> Non_Magnetic_object_list;   //pointers of non-magnetic material in world
