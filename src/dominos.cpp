/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

/* 
 * Base code for CS 251 Software Systems Lab 
 * Department of Computer Science and Engineering, IIT Bombay
 * 
 */

#include <iostream>
using namespace std;
#include "cs251_base.hpp"
#include <vector>
#include "render.hpp"
#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include "GL/freeglut.h"
#endif

#include <cstring>
using namespace std;

#include "dominos.hpp"
namespace cs251
{
	

  dominos_t::dominos_t()
  {
    
    m_world->SetGravity(b2Vec2(0.0, 0.0));

    	

    	b2PolygonShape leftshape;					//floor at the left
	    leftshape.SetAsBox(0.1f, 50.0f);
	    b2BodyDef leftbd;
	    leftbd.position.Set(-45.0f, 25.0f);
	    leftbd.type = b2_staticBody;
	    b2Body* leftbody = m_world->CreateBody(&leftbd);
	    b2FixtureDef *leftfd = new b2FixtureDef;
	    leftfd->density = 1.0f;
	    leftfd->restitution=.5f;
	    leftfd->shape = new b2PolygonShape;
	    leftfd->shape = &leftshape;
	    leftbody->CreateFixture(leftfd);


	    b2PolygonShape rightshape;					//floor at the right 
	    rightshape.SetAsBox(0.1f, 50.1f);
	    b2BodyDef rightbd;
	    rightbd.position.Set(45.0f, 25.0f);
	    rightbd.type = b2_staticBody;
	    b2Body* rightbody = m_world->CreateBody(&rightbd);
	    b2FixtureDef *rightfd = new b2FixtureDef;
	    rightfd->density = 1.0f;
	    rightfd->restitution=.5f;
	    rightfd->shape = new b2PolygonShape;
	    rightfd->shape = &rightshape;
	    rightbody->CreateFixture(rightfd);

	    b2PolygonShape upshape;					//floor at the top
	    upshape.SetAsBox(50.1f, 0.1f);
	    b2BodyDef upbd;
	    upbd.position.Set(0.0f, 45.0f);
	    upbd.type = b2_staticBody;
	    b2Body* upbody = m_world->CreateBody(&upbd);
	    b2FixtureDef *upfd = new b2FixtureDef;
	    upfd->density = 1.0f;
	    upfd->restitution=.5f;
	    upfd->shape = new b2PolygonShape;
	    upfd->shape = &upshape;
	    upbody->CreateFixture(upfd);

	    b2PolygonShape shape2;					//floor at the bootom 
	    shape2.SetAsBox(50.0f, 0.1f);
	    b2BodyDef bd22;
	    bd22.position.Set(0.0f, 2.5f);
	    bd22.type = b2_staticBody;
	    b2Body* body2 = m_world->CreateBody(&bd22);
	    b2FixtureDef *fd22 = new b2FixtureDef;
	    fd22->density = 1.0f;
	    fd22->restitution=.5f;
	    fd22->shape = new b2PolygonShape;
	    fd22->shape = &shape2;
	    body2->CreateFixture(fd22);

	    Magnetic_object *static1 = new Magnetic_object(-15.0f,20.0f,m_world);
	    Magnetic_object_list.push_back(static1);
	    Non_magnetic_object *dynamic1= new Non_magnetic_object(0.0f,25.0f,m_world);
	    Non_Magnetic_object_list.push_back(dynamic1);
	    Magnetic_object *static2 = new Magnetic_object(15.0f,20.0f,m_world);
	    Magnetic_object_list.push_back(static2);
	    Non_magnetic_object *dynamic2= new Non_magnetic_object(4.0f,35.0f,m_world);
	    Non_Magnetic_object_list.push_back(dynamic2);
}
  

  sim_t *sim = new sim_t("Magnetic materials", dominos_t::create);
}
