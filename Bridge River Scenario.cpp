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

void circleSolid(float x, float y, float radius){
	int triangleAmount = 100; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(x, y); // center of circle
	
    for(int i = 0; i <= triangleAmount; i++){
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void vehicleTruck(int val){//Truck
    glPushMatrix();
    glTranslatef(truckPosition,0.0f, 0.0f);

   //B O D Y
   
    glColor3ub(0,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.68f, -0.86f);
    glVertex2f(-0.68f,-0.67f);
    glVertex2f(-0.9f,-0.67f);
    glEnd();

    //Truck Base
    
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.9f);
    glVertex2f(-0.9f,-0.9f);
    glEnd();

    //Truck Front
    
    glColor3ub(240,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.67f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.79f);
    glVertex2f(-0.61f,-0.735f);
    glVertex2f(-0.67f,-0.735f);
    glEnd();

    //Wheels
    
    glColor3ub(20,20,120);
    circleSolid(-0.84f,-0.88f,0.034);
    circleSolid(-0.64f,-0.88f,0.034);
    glColor3ub(130,130,130);
    circleSolid(-0.84f,-0.88f,0.02);
    circleSolid(-0.64f,-0.88f,0.02);

    //Door
    
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-.59619,-0.815);
    glVertex2f(-0.61,-0.815);
    glEnd();

   //window
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(-0.66,-0.797);
    glVertex2f(-0.596,-0.797);
    glVertex2f(-0.596,-0.781);
    glColor3ub(100,149,237);
    glVertex2f(-0.615,-0.747);
    glVertex2f(-0.66,-0.747);
    glEnd();

    if(val == 9){
    glBegin(GL_TRIANGLES); //light
      glColor3f(1.0f,1.f,0.0f);
      glVertex2f(-0.4f, -0.9f);
      glVertex2f(-0.4f,  -0.8f);
      glVertex2f(-0.58f, -0.85f);
    glEnd();
    }
    glPopMatrix();
}

void vehicleCar(int val){// Car part
    
    glPushMatrix();
    glTranslatef(carPosition,0.0f, 0.0f);
    
    //B O D Y
    
    glColor3ub(199, 0, 57 );
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,-0.94f);
    glVertex2f(0.275f, -0.94f);
    glVertex2f(0.275f,-0.859f);
    glVertex2f(0.22f,-0.842f);
    glVertex2f(0.18f,-0.758f);
    glVertex2f(0.1f, -0.758f);
    glVertex2f(0.08f,-0.842f);
    glVertex2f(0.0f,-0.856f);
    glEnd();
    
    //W H E E L S
    
    glColor3ub(103,13,124);
    circleSolid(0.07,-0.938,0.035);
    circleSolid(0.2,-0.938,0.035);
    
    //
    
    glColor3ub(0,0,0);
    glLineWidth(1.1);
    glBegin(GL_LINES);
    glVertex2f(0.141f,-0.758f);
    glVertex2f(0.141f,-0.842f);
    glEnd();
    

    //W I N D O W

    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(0.071,-0.842);
    glVertex2f(0.132,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.132,-0.77);
    glVertex2f(0.106,-0.77);
    glEnd();

    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(0.148,-0.842);
    glVertex2f(0.206,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.173,-0.77);
    glVertex2f(0.148,-0.77);
    glEnd();

    // D O O R
    
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0.11,-0.863);
    glVertex2f(0.13,-0.863);
    glVertex2f(0.186,-0.863);
    glVertex2f(0.206,-0.863);
    glColor3ub(255,255,255);
    glEnd();

    if(val == 9){
    glBegin(GL_TRIANGLES); // L I G H T
      glColor3f(1.0f,1.f,0.0f);
      glVertex2f(-0.15f, -0.84f);
      glVertex2f(-0.15f,  -0.93f);
      glVertex2f(0.018f, -0.90f);
    glEnd();
    }
    glPopMatrix();
}

void boat(int vehicle){ // B O A T 
    glPushMatrix();
    glTranslatef(boatPosition,0.0f, 0.0f);
    if (vehicle == 1)
        glColor3ub(255,110,0);
    if (vehicle == 2)
        glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.69f, -0.30f);
    glVertex2f(-0.62f, -0.30f);
    glVertex2f(-0.58f, -0.24f);
    glVertex2f(-0.73f, -0.24f);
    glEnd();

    // S T I C K 
    glColor3ub(160,82,35);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-0.65,-0.24);
    glVertex2f(-0.65,-0.1);
    glEnd();

    glColor3ub(0,255,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.655,-0.13);
    glVertex2f(-0.655,-0.24);
    glVertex2f(-0.71,-0.24);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.645,-0.13);
    glVertex2f(-0.645,-0.24);
    glVertex2f(-0.580,-0.24);
    glEnd();
	
void cloud2(int value){
    if(position1>1.0) 
        position1 = -1.0f;
        position1 += speed;
	
	glutPostRedisplay();
	glutTimerFunc(100, cloud2, 0);
}
    glPopMatrix();
}

void sun(int sval){
	x=-0.8f; y=0.85f; radius =0.1f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	if(sval==1) glColor3ub(255, 224, 102);
    if(sval==8) glColor3ub(226, 148, 13);
    
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++){
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void cloud(int val){ // C L O U D 2
    
    glPushMatrix();
	glTranslatef(position1,0.0f, 0.0f);
	x=0.0f; y=0.9f; radius =.1f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;

	if(val==1) glColor3ub(255, 255, 255);
    if(val==9) glColor3ub(110, 113, 115);

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-0.1f; y=0.9f; radius =.07f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;

	if(val==1) glColor3ub(255, 255, 255);
    if(val==9) glColor3ub(110, 113, 115);
        
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	
	glPopMatrix();
}

// W I N D M I L L

int frameNumber = 0; 
void doFrame(int v){ // W I N D M I L L Rotate
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

void hill(int val){

    glBegin(GL_POLYGON); // Back of the H I L L
        if(val==1) glColor3f(0.0f, 0.3f, 0.0f);
        if(val==9) glColor3f(0.03f, 0.23f, 0.02f);

        glVertex2f(-1.0f, 0.4f);
        glVertex2f(-1.0f, 0.7f);
        glVertex2f(-0.9f, 0.75f);
        glVertex2f(-0.7f, 0.73f);
        glVertex2f(-0.4f, 0.78f);
        glVertex2f(-0.1f, 0.86f);
        glVertex2f(0.5f, 0.65f);
        glVertex2f(0.9f, 0.73f);
        glVertex2f(1.0f, 0.7f);
        glVertex2f(1.0f, 0.4f);

    glEnd();
    glBegin(GL_POLYGON); 
    
    // Second lift of H I L L

    if(val==1) glColor3f(0.0f, 0.5f, 0.0f);
    if(val==9) glColor3f(0.04f, 0.29f, 0.02f);

        glVertex2f(-0.6f, 0.4f);
        glVertex2f(-0.4f, 0.55f);
        glVertex2f(-0.2f, 0.6f);
        glVertex2f(-0.15f, 0.55f);
        glVertex2f(0.0f, 0.50f);
        glVertex2f(0.15f, 0.53f);
        glVertex2f(0.3f, 0.4f);

    glEnd();
}

void hill3rd(int val){
    
    glBegin(GL_POLYGON); // Third H I L L 

    if(val==1) glColor3f(0.0f, 0.5f, 0.0f);
    if(val==9) glColor3f(0.04f, 0.29f, 0.02f);

        glVertex2f(0.35f, 0.4f);
        glVertex2f(0.45f, 0.5f);
        glVertex2f(0.77f, 0.61f);
        glVertex2f(.83f, 0.49f);
        glVertex2f(1.0f, 0.4f);

    glEnd();

    glBegin(GL_POLYGON);  // Third right shadow of H I L L

    if(val==1) glColor3f(0.0f, 0.7f, 0.0f);
    if(val==9) glColor3f(0.0f, 0.52f, 0.0f);

        glVertex2f(0.35f, 0.4f);
        glVertex2f(0.45f, 0.5f);
        glVertex2f(0.77f, 0.61f);
        glVertex2f(0.6f, 0.58f);
        glVertex2f(0.5f, 0.56f);
        glVertex2f(0.55f, 0.5f);
        glVertex2f(0.57f, 0.45f);
        glVertex2f(0.59f, 0.4f);

    glEnd();
}

void sky(int val){ // C H A N G E C O L O R

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to BLACK and OPAQUE
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glBegin(GL_POLYGON);        // S K Y 

    if(val==1){
        glColor3ub(0,0,255);
        glVertex2f(-1.0f, 1.0f);

        glColor3ub(138, 105, 14);
        glVertex2f( 1.0f, 1.0f);

        glColor3ub(138, 67, 46);
        glVertex2f( 1.0f, 0.5f);

        glColor3ub(235, 158, 59);
        glVertex2f(-1.0f, 0.5f);
    }

    if(val==8){
        glColor3ub(193, 214, 58);
        glVertex2f(-1.0f, 1.0f);

        glColor3ub(214, 170, 24);
        glVertex2f( 1.0f, 1.0f);

        glColor3ub(27, 191, 164);
        glVertex2f( 1.0f, 0.5f);

        glColor3ub(94, 190, 209);
        glVertex2f(-1.0f, 0.5f);
}

    if(val==9){
        glColor3ub(28,142,255);
        glVertex2f(-1.0f, 1.0f);

        glColor3ub(18,8,54);
        glVertex2f( 1.0f, 1.0f);

        glColor3ub(18,8,54);
        glVertex2f( 1.0f, 0.5f);

        glColor3ub(18,8,54);
        glVertex2f(-1.0f, 0.5f);
    }

    glEnd();
}

void windmill(int val){ // Change Windmill
    int i;
    
    if(val==1) glColor3f(0.8f, 0.8f, 0.9f);
    if(val==9) glColor3f(0.40f, 0.45f, 0.53f);

	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	
	glTranslatef(0, 3, 0);
	glRotated(frameNumber * (180.0/46), 0, 0, 1);

    if(val==1) glColor3f(0.4f, 0.4f, 0.8f);
	
    if(val==9) glColor3f(0.16f, 0.12f, 0.30f);
    for (i = 0; i < 3; i++){	
	glRotated(120, 0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0.5f, 0.1f);
        glVertex2f(1.5f,0);
        glVertex2f(0.5f, -0.1f);
        glEnd();
   }
}

void bridgeTop(){ // T O P of Bridge
    
    glBegin(GL_POLYGON);
    glColor3ub (150, 161, 177);
    glVertex2f(0.60f, -0.10f);
    glVertex2f(0.60f, -0.15f);
    glColor3ub (70,87,112);
    glVertex2f(-1.2f, 0.15f);
    glVertex2f(-1.2f, 0.20f);
    
    glEnd();
}

void bridgeSupport(){ //Bridge Support
    
    glBegin(GL_POLYGON);
    glColor3ub (70,87,112);
    glVertex2f(-1.0f, 0.15f);
    glVertex2f(-1.0f, 0.12f);
    glVertex2f(-0.835f, 0.042f);
    glVertex2f(-0.785f, 0.042f);
    glVertex2f(-0.6f, 0.043f);
    glVertex2f(-0.6f, 0.075f);
    
    glEnd();
}

void bridge(){
    bridgeTop();
    
    glPushMatrix(); // Bridge Pillar Remove
    glTranslatef(0.0f,0.005f,0.0f);
    bridgeSupport();
    bridgePillers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4f,-0.069f,0.0f);
    bridgeSupport();
    glTranslatef(0.0f,0.011f,0.0f);
    glScaled(1,0.79,1);
    bridgePillers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8f,-0.145f,0.0f);
    bridgeSupport();
    glTranslatef(0.0f,0.019f,0.0f);
    glScaled(1,0.58,1);
    bridgePillers();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1994f,-0.22f,0.0f);
    bridgeSupport();
    glTranslatef(0.0f,0.026f,0.0f);
    glScaled(1,0.38,1);
    bridgePillers();
    glPopMatrix();

}

void lampPost_panelRoad(int val){
    
    // Main Panel

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.39f, 0.47f);

        glVertex2f(-0.025f, 0.2f);
        glVertex2f(0.025f, 0.2f);
        glVertex2f(0.025f, -0.9f);
        glVertex2f(-0.025f, -0.9f);

    glEnd();


//////////////////////////

//////////////////////////

    // Right Panel Shadow

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.25f, 0.30f);

        glVertex2f(0.0f, 0.2f);
        glVertex2f(0.025f, 0.2f);
        glVertex2f(0.025f, -0.9f);
        glVertex2f(0.0f, -0.9f);

    glEnd();

//////////////////////////

//////////////////////////

    // J O I N T

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.39f, 0.47f);

        glVertex2f(-0.05f, 0.2f);
        glVertex2f(0.0f, 0.2f);
        glVertex2f(-0.05f, 0.3f);
        glVertex2f(-0.1f, 0.3f);

    glEnd();

//////////////////////////

//////////////////////////

    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.16f, 0.20f);

        glVertex2f(0.05f, 0.2f);
        glVertex2f(0.0f, 0.2f);
        glVertex2f(0.05f, 0.3f);
        glVertex2f(0.1f, 0.3f);

    glEnd();

    // T U B E Holder

    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.39f, 0.47f);

        glVertex2f(-0.05f, 0.25f);
        glVertex2f(-0.05f, 0.3f);
        glVertex2f(-0.55f, 0.3f);
        glVertex2f(-0.55f, 0.25f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.16f, 0.20f);

        glVertex2f(0.05f, 0.25f);
        glVertex2f(0.05f, 0.3f);
        glVertex2f(0.55f, 0.3f);
        glVertex2f(0.55f, 0.25f);

    glEnd();

    // T U B E

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.25f, 0.30f);

        glVertex2f(-0.55f, 0.25f);
        glVertex2f(-0.6f, 0.2f);
        glVertex2f(-0.1f, 0.2f);
        glVertex2f(-0.15f, 0.25f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.25f, 0.30f);

        glVertex2f(0.55f, 0.25f);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.1f, 0.2f);
        glVertex2f(0.15f, 0.25f);

    glEnd();


//////////////////////////

//////////////////////////

	// Solar Panel


    if(val == 9){
        glBegin(GL_POLYGON);
        glColor4f(1.0f, 1.0f, 0.0f, 5.0f);

            glVertex2f(0.6f, 0.2f);
            glVertex2f(0.1f, 0.2f);
            glVertex2f(0.15f, 0.15f);
            glVertex2f(0.55f, 0.15f);

        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(1.0f, 1.0f, 0.0f, 5.0f);

            glVertex2f(-0.6f, 0.2f);
            glVertex2f(-0.1f, 0.2f);
            glVertex2f(-0.15f, 0.15f);
            glVertex2f(-0.55f, 0.15f);
        glEnd();
    }
}

// R I V E R

void roadriver(int val){
    glBegin(GL_POLYGON); 
    
    if(val==9)
        glColor3f(0,0,128);
        glVertex2f( 1.0f, -0.30f);

        glColor3f(0,0,128);
        glVertex2f(-1.0f, -0.30f);

        glColor3f(0,0,128);
        glVertex2f(-1.0f, 0.295f);

        glColor3f(0,0,128);
        glVertex2f( 1.0f, 0.295f);

    if(val==1)
        glColor3f(0,0,128);
        glVertex2f( 1.0f, -0.30f);

        glColor3f(0,0,128);
        glVertex2f(-1.0f, -0.30f);

        glColor3f(0,0,128);
        glVertex2f(-1.0f, 0.295f);

        glColor3f(0,0,128);
        glVertex2f( 1.0f, 0.295f);

    glEnd();
