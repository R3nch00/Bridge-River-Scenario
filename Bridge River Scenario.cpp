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
