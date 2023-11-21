// mes que un club //
#include<bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<Windows.h>
#include<Mmsystem.h>
#define PI 3.14159265358979323846

void displayMor();

GLfloat position = -0.5f; //cloud1
GLfloat position1 = 0.5f; //cloud2
GLfloat speed = 0.02f;

//GLfloat speed1 = 0.02f;

GLfloat x, y, radius, twicePi;
int triangleAmount; //sun
int rval = 0;
char play = '1';

void initGL(){ glClearColor(0.0f, 0.0f, 0.0f, 1.0f); } // Black and opaque

void Idle(){ glutPostRedisplay(); } // marks the current window as needing to be redisplayed

void automated_mor(int val){ glutDisplayFunc(displayMor); }

GLfloat positionBridgeCar1 = -5.0f;
GLfloat speedBridgeCar1 = 0.08f;

void updateBridgeCar1(int value){ //2
    if(positionBridgeCar1 > 4.0)
        positionBridgeCar1 = -8.2f;
        positionBridgeCar1 += speedBridgeCar1;
        glutPostRedisplay();
        glutTimerFunc(100, updateBridgeCar1, 0);
}

GLfloat truckPosition = 0.0f;
GLfloat truckSpeed = 0.08f;

void updateTruck(int value){ //5
    if(truckPosition>1.45){ truckPosition = -0.4f; }
    truckPosition += truckSpeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateTruck, 0);
}

GLfloat boatPosition = 0.0f;
GLfloat boatSpeed = 0.02f;

void updateBoat(int value){
    if(boatPosition > 1.45){ boatPosition = 0; }
    boatPosition += boatSpeed;
	glutPostRedisplay();
	glutTimerFunc(100, updateBoat, 0);
}

GLfloat carPosition = 0.0f;
GLfloat carSpeed = 0.05f;
void updateCar(int value){ //car utso
    if(carPosition < - 1.0){ carPosition = 0.6f; }
    carPosition -= carSpeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateCar, 0);
}

void bridgeCar1(int val){ //Car body
    glPushMatrix();
    glTranslatef(positionBridgeCar1,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, .0f, 0.0f);
    glVertex2f(-0.1f, 0.3f);
    glVertex2f(0.4f, 0.3f);
    glVertex2f(0.5f, 0.2f);
    glVertex2f(0.7f, 0.2f);
    glVertex2f(0.7f, 0.0f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.1f, 0.28f);
    glVertex2f(0.4f, 0.28f);
    glVertex2f(0.45f, 0.22f);
    glVertex2f(0.1f, 0.22f);
glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.1f, 0.28f);
    glVertex2f(0.05f, 0.28f);
    glVertex2f(0.05f, 0.22f);
    glVertex2f(-0.15f, 0.22f);
glEnd();

    glBegin(GL_POLYGON); //Tube light
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.6f, 0.15f);
    glVertex2f(0.7f, 0.15f);
    glVertex2f(0.7f, 0.1f);
    glVertex2f(0.6f, 0.1f);
glEnd();

    float t1_angle; //Tire 1
    float t1_radius=0.1;
    float t1_x,t1_y,t1_p,t1_q;
    
    t1_x = -0.1f; t1_y = 0.0f;
    
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(t1_x, t1_y);
    for(t1_angle = 0.0f; t1_angle<360.0f; t1_angle++){
        t1_p = t1_x+sin(t1_angle)*t1_radius;
        t1_q = t1_y+cos(t1_angle)*t1_radius;
        glVertex2f(t1_p,t1_q);
    }
glEnd();

    float i1_angle;// Tire 1 Inside
    float i1_radius = 0.07;
    float i1_x,i1_y, i1_p, i1_q;

    i1_x = -0.1f; i1_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(i1_x,i1_y);
    for(i1_angle = 0.0f; i1_angle<360.0f; i1_angle++){
        i1_p = i1_x+sin(i1_angle)*i1_radius;
        i1_q = i1_y+cos(i1_angle)*i1_radius;
        glVertex2f(i1_p,i1_q);
    }
glEnd();

    float t2_angle; //Tire 2
    float t2_radius = 0.1;
    float t2_x,t2_y, t2_p, t2_q;

    t2_x = 0.4f;t2_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(t2_x,t2_y);
    for(t2_angle = 0.0f; t2_angle<360.0f; t2_angle++){
        t2_p = t2_x+sin(t2_angle)*t2_radius;
        t2_q = t2_y+cos(t2_angle)*t2_radius;
        glVertex2f(t2_p,t2_q);
    }
glEnd();

    float i2_angle;//Tire 2 Inside
    float i2_radius = 0.07;
    float i2_x,i2_y, i2_p, i2_q;

    i2_x = 0.4f;i2_y = 0.0f;

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(i2_x,i2_y);
    for(i2_angle = 0.0f; i2_angle<360.0f; i2_angle++){
        i2_p = i2_x+sin(i2_angle)*i2_radius;
        i2_q = i2_y+cos(i2_angle)*i2_radius;
        glVertex2f(i2_p,i2_q);
    }
glEnd();

    if(val == 9){
        glBegin(GL_TRIANGLES); //light
        glColor3f(1.0f,1.f,0.0f);
        glVertex2f(0.95f,  0.2f);
        glVertex2f(0.69f,  0.12f);
        glVertex2f(0.95f,  -0.03f);
    glEnd();
   }
    glPopMatrix();
}
