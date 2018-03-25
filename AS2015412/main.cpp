/** HADG JANITH
    AS2015412

    15ASP137**/



#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>



GLuint tex;
GLUquadric* sphere;

GLfloat gfPosX = 0.0;
GLfloat gfDeltaX = 0.01 ;

GLfloat gfPosXB = 0.0;
GLfloat gfDeltaXB = 0.03 ;

GLfloat gfPosXC = 0.0;
GLfloat gfDeltaXC = 0.04 ;

GLfloat density = 0.3; //set the density to 0.3 which is acctually quite thick

GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0}; //set the for color to grey

int exit1=-1;


 double zRotation;
GLfloat pos_x = 0, pos_y = 0;

void specialKeys( int key, int x, int y ){/**TO STEER THE CAR**/
    const float step = 0.01;
    switch(key){
        case GLUT_KEY_RIGHT:
            pos_x += step;
        break;
        case GLUT_KEY_LEFT:
            pos_x -= step;
        break;
        case GLUT_KEY_UP:
            pos_y += step;
             zRotation +=10;
        break;
        case GLUT_KEY_DOWN:
            pos_y -= step;
             zRotation -=10;
        break;
    }
    glutPostRedisplay();

}

void make_tex(void)/**Add a texture to the background[HALF IMPLIMENTED]**/
{/*
    unsigned char data[256][256][3];
    for (int y = 0; y < 255; y++) {
	for (int x = 0; x < 255; x++) {
	    unsigned char *p = data[y][x];
	    p[0] = p[1] = p[2] = (x ^ y) & 8 ? 255 : 0;
	}
    }
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, (const GLvoid *) data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);**/
}


void DrawGround()/**Terrain[By triangles]**/{
glFlush();
    float **hgtmap;
    int elems=300;

  hgtmap = new float*[elems]; // allocate "main" array - "rows"
  for(int x=0; x<elems; x++)
	{
	  hgtmap[x] = new float[elems]; // allocate member of "main" - "columns"
	  for(int z=0; z<elems; z++)
		{
		  hgtmap[x][z] = 0.05f*(float)(rand()%10); // create height map
		}
	}



GLfloat fExtent = 20.0f; // total length in each direction
  GLfloat fStep = 1.0f; // length of each step






  GLfloat xVal, zVal; // xVal = x-coordinate, zVal = z-coordinate
  int countX = 0;
  int countZ = 0;

  glColor3f(0.60f, .40f, .10f); // red/green/blue
  //  glShadeModel(GL_FLAT); // ??? Need this?
  for(xVal = -fExtent; xVal <= fExtent; xVal += fStep)
	{
	  countX += 1;
	  countZ = 0;

	  glBegin(GL_TRIANGLE_STRIP);
	  glNormal3f(0.0f, 1.0f, 0.0f); // surface normal: UP - WRONG?
	  for(zVal = fExtent; zVal >= -fExtent; zVal -= fStep)
		{
		  countZ += 1;
		  glVertex3f(xVal, hgtmap[countX-1][countZ-1], zVal);
		  glVertex3f(xVal + fStep, hgtmap[countX][countZ-1], zVal);
		} // for(zVal = fExtent; zVal >= -fExtent; zVal -= fStep)



	  glEnd();
	} // for(xVal = -fExtent; xVal <= fExtent; xVal += fStep)

  glShadeModel(GL_SMOOTH);
 // end of Drawground function
glFlush();
}


void track(){
glFlush();

/**left side barrier**/
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-5,1,-6);
    glScalef(50,2,.1);
    glLineWidth(2);
    glutSolidCube(1);
    glPopMatrix();


 /**Right side barrier**/
   glPushMatrix();
   glColor3f(1,0,0);
   glTranslatef(-5,1,6);
   glScalef(50,2,.1);
   glLineWidth(2);
   glutSolidCube(1);
   glPopMatrix();

glFlush();

}

void sideBars(){
    glFlush();
/**left side**/
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(30-gfPosX,1,-6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(25-gfPosX,1,-6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(20-gfPosX,1,-6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();

    glPushMatrix();
    glTranslatef(15-gfPosX,1,-6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }

	glPopMatrix();
	glPushMatrix();
    glTranslatef(10-gfPosX,1,-6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();

	glPushMatrix();
    glTranslatef(5-gfPosX,1,-6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0-gfPosX,1,-6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();

	glPushMatrix();
    glTranslatef(-5-gfPosX,1,-6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();


	/**right side**/
	glPushMatrix();
    glTranslatef(30-gfPosX,1,6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();


	glPushMatrix();
    glTranslatef(25-gfPosX,1,6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();

    glPushMatrix();
    glTranslatef(20-gfPosX,1,6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();

    glPushMatrix();
    glTranslatef(15-gfPosX,1,6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }

	glPopMatrix();
	glPushMatrix();
    glTranslatef(10-gfPosX,1,6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();

	glPushMatrix();
    glTranslatef(5-gfPosX,1,6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0-gfPosX,1,6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 35.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();

	glPushMatrix();
    glTranslatef(-5-gfPosX,1,6);
    glScalef(.4,4,.4);
	glutSolidCube(1);
	gfPosX += gfDeltaX;
        if (gfPosX >= 25.0 || gfPosX <= 0.0) {
            gfPosX = 0.0;
        }
	glPopMatrix();

glFlush();

}

void tree3(GLfloat q1,GLfloat w1){
    glFlush();
    glPushMatrix();
    glColor3f(0.9,.4,0.4);
    glTranslatef(q1-gfPosXB ,1 ,w1);
    glScalef(.3,4,.3);
	glutSolidCube(2);


	gfPosXB += gfDeltaXB;
        if (gfPosXB >= 60.0 || gfPosXB <= 0.0) {
            gfPosXB = 0.0;
        }
	glPopMatrix();

    glPushMatrix();
	glColor3f(0,.9,0);
	glTranslatef(q1-gfPosXB,3,w1);
    glRotatef(-90,1,0,0);
	glutSolidCone(2,4,35,45);

	gfPosXB += gfDeltaXB;
        if (gfPosXB >= 60.0 || gfPosXB <= 0.0) {
            gfPosXB = 0.0;
        }
	glPopMatrix();

glFlush();

}

double TREE_FACTOR =4;
double TREE_LINE_BASE_LEN=10;
/**tree by recrusion[HALF IMPLEMENTED]**/
void drawTree(int currentDepth, int maxDepth){
    glFlush();
    glPushMatrix();
    glTranslatef(-4,1,-7);
    if (currentDepth > maxDepth)
        return;

    if (currentDepth <= maxDepth - 2)
    {
        glColor3d(0.45, 0.2, 0.05);
        glLineWidth(10 * static_cast<GLfloat>(pow(TREE_FACTOR, currentDepth)));
    }
    else
    {
        glColor3d(0, 0.5, 0);
        glLineWidth(30 * static_cast<GLfloat>(pow(TREE_FACTOR, currentDepth)));
    }

    double lineLen = TREE_LINE_BASE_LEN * pow(TREE_FACTOR, currentDepth);
    glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(0, lineLen);
    glEnd();

    int angle1 = 10 + rand() % 40;
    int angle2 = 10 + rand() % 40;

    glTranslated(0, lineLen, 0);
    glRotated(-angle1, 0, 0, 1);
    drawTree(currentDepth + 1, maxDepth);
    glRotated(angle1 + angle2, 0, 0, 1);
    drawTree(currentDepth + 1, maxDepth);
    glRotated(-angle2, 0, 0, 1);
    glTranslated(0, -lineLen, 0);
    glPopMatrix();

    glFlush();
}
void startPole(){/**OBJECT THAT TRIED TO ADD TEXTURE**/
    glFlush();
     glClearColor(0.5, 0.5, 1.0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0,-2.0);
    glRotatef(45, 0, 1, 0);

    glColor3f(1.0,1.0,1.0);
    gluQuadricDrawStyle(sphere, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, tex);
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    //gluCylinder(sphere, 1.0, 32, 16);
    gluCylinder(sphere,1,1,6,1,1);


    glutSwapBuffers();
    glFlush();
}

void house(){

    glPushMatrix();
    glScalef(2,1.5,1.5);
    glTranslatef(5-gfPosXB,1,8);
    glColor3f(1,1,1);
    glPolygonMode(GL_FRONT, GL_FILL); //GL_FILL or GL_POINT
    glEdgeFlag(GL_FALSE); //for line mode

    glBegin(GL_POLYGON); // Draw front face
        glColor3f(0,0,.5);
        glVertex3f(-1, 1, 1);
        glVertex3f(0, 1.5, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, -1, 1);
        glVertex3f(-1, -1, 1);
    glEnd();

    glBegin(GL_POLYGON); // Draw back square CW
        glVertex3f(-1, 1, -3);
        glVertex3f(0, 1.5, -3);
        glVertex3f(1, 1, -3);
        glVertex3f(1, -1, -3);
        glVertex3f(-1, -1, -3);
    glEnd();

    glBegin(GL_QUAD_STRIP); // Connect vertices of two squares using QUADS
        glColor3f(0,0,-.5);
        glVertex3f(-1, 1, 1); glVertex3f(-1, 1, -3);
        glVertex3f(0, 1.5, 1); glVertex3f(0, 1.5, -3);
        glVertex3f(1, 1, 1); glVertex3f(1, 1, -3);
        glVertex3f(1, -1, 1); glVertex3f(1, -1, -3);
        glVertex3f(-1, -1, 1); glVertex3f(-1, -1, -3);
    glEnd();

    glBegin(GL_QUADS); //  DOOR
    glColor3f(1.0,1.0,0.0);
        glVertex3f(-.2, 0, 1);
        glVertex3f(.2, 0, 1);
        glVertex3f(.2, -1, 1);
        glVertex3f(-.2, -1, 1);
    glEnd();

    glBegin(GL_QUADS); //  WINDOOR
        glVertex3f(1, 0.2, -1.5);
        glVertex3f(1, 0.2, -2.5);
        glVertex3f(1, .2, -2.5);
        glVertex3f(1, -0.2, -1.5);
    glEnd();

    gfPosXB += gfDeltaXB;
        if (gfPosXB >= 60.0 || gfPosXB <= 0.0) {
            gfPosXB = 0.0;
        }
	glPopMatrix();
    glPopMatrix();

glFlush();

}

void buildings(){
    glFlush();
    glPushMatrix();
    glColor3f(0.8,.8,0.8);
    glTranslatef(35-gfPosXB,1,-14);
    glScalef(4,4,4);
	glutSolidCube(2);
	glColor3f(0,0,0);
	glScalef(1,.5,1);
	glutWireCube(2.01);
	gfPosXB += gfDeltaXB;
        if (gfPosXB >= 60.0 || gfPosXB <= 0.0) {
            gfPosXB = 0.0;
        }
	glPopMatrix();

	glFlush();

}

void car(){

    glFlush();
    /**CAR **/

   glColor3f(1,1,0);
   glPushMatrix();
   glTranslatef(-5+pos_y*4,1,0+pos_x*20);
   glScalef(5,1,2);
   glLineWidth(2);
   glutSolidCube(1);
   glutWireCube(1);
   glColor3f(0,0,0);
   glLineWidth(3);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-5+pos_y*4,1,0+pos_x*20);
   glScalef(5.01,1.01,2.01);
   glLineWidth(2);
   glutWireCube(1);
   glColor3f(0,0,0);
   glLineWidth(3);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-5+pos_y*4,1.75,0+pos_x*20);
   glScalef(2,0.5,1.8);
   glLineWidth(2);
   glutSolidCube(1);
   glLineWidth(1);
   glPopMatrix();

/**doors**/
    glPushMatrix();
    glTranslatef(-8+pos_y*4,0,0+pos_x*20);
    glLineWidth(2);
    glBegin(GL_LINES);
    glFrontFace(GL_CW); // Connect vertices of two squares using lines
    glColor3f(0,0,0);
    glVertex3f(2, 1.5, -1); glVertex3f(4, 1.5, -1);
    glVertex3f(4, 1.5, -1); glVertex3f(4, .5, -1);
    glVertex3f(2, .5, -1); glVertex3f(4, .5, -1);
    glVertex3f(2, 1.5, -1); glVertex3f(2, .5, -1);
    glEnd();
    glLineWidth(2);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-8+pos_y*4,0,0+pos_x*20);
    glLineWidth(2);
    glBegin(GL_LINES);
    glFrontFace(GL_CW); // Connect vertices of two squares using lines
    glColor3f(0,0,0);
    glVertex3f(2, 1.5, 1); glVertex3f(4, 1.5, 1);
    glVertex3f(4, 1.5, 1); glVertex3f(4, .5, 1);
    glVertex3f(2, .5, 1); glVertex3f(4, .5, 1);
    glVertex3f(2, 1.5, 1); glVertex3f(2, .5, 1);
    glEnd();
    glLineWidth(2);
    glPopMatrix();

/**Wheels**/
   glPushMatrix();
   glTranslatef(-5+2.1+pos_y*4,0.5,1+pos_x*20);
   glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-5+2.1+pos_y*4,0.5,-1+pos_x*20);
  glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-5+-2.1+pos_y*4,0.5,1+pos_x*20);
   glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-5+-2.1+pos_y*4,0.5,-1+pos_x*20);
  glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();



/**BreakLights**/
   glPushMatrix();
   glColor3f(1,0,0);
   glTranslatef(-5+-2.5+pos_y*4,1.3,-.9+pos_x*20);
   glRotatef(10,0.0,pos_x*9+2,0);
   glScalef(0.1,0.1,0.1);
   glutSolidSphere(1,12,12);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-5+-2.5+pos_y*4,1.3,.9+pos_x*20);
   glScalef(0.1,0.1,0.1);
   glutSolidSphere(1,12,12);
   glPopMatrix();

   glPushMatrix();
   glColor3f(.5,0,0);
   glTranslatef(-5+-2.5+pos_y*4,1.1,-.9+pos_x*20);
   glRotatef(10,0.0,pos_x*9+2,0);
   glScalef(0.1,0.1,0.1);
   glutSolidSphere(1,12,12);
   glPopMatrix();

   glPushMatrix();
   glColor3f(.5,0,0);
   glTranslatef(-5+-2.5+pos_y*4,1.1,.9+pos_x*20);
   glRotatef(10,0.0,pos_x*9+2,0);
   glScalef(0.1,0.1,0.1);
   glutSolidSphere(1,12,12);
   glPopMatrix();



   /**Rear bumper**/

   glPushMatrix();
   glColor3f(1,.4,0);
   glTranslatef(-5+-2.5+pos_y*4,.7,.02+pos_x*20);
   glScalef(1,1,11);
   glutSolidCube(.2);
   glPopMatrix();

   /**Number plate**/

   glPushMatrix();
   glLineWidth(1);
   glColor3f(1,1,1);
   glTranslatef(-5.1+-2.5+pos_y*4,.7,.02+pos_x*20);
   glScalef(1,1,5);
   glutSolidCube(.2);
   glPopMatrix();

   /**Number plate text**/

    glPushMatrix();
	glColor3f(0,0,0);
    glTranslatef(-5.3+-2.5+pos_y*4,.7,-.45+pos_x*20);
    glRotatef(-90,0,1,0);
	glScalef(.001,.001,.03);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'A');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'S');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'2');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'0');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'1');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'5');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'4');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'1');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'2');
	glPopMatrix();

    glFlush();

}

void enemyCar1(GLfloat a1,GLfloat b1){
    glFlush();
   glPushMatrix();
    glColor3f(0,1,1);
   glTranslatef(a1-gfPosXC,1,b1);
   glScalef(5,1,2);
   glutSolidCube(1);
   glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
   glTranslatef(a1-gfPosXC,1.75,b1);
   glScalef(2,0.5,1.8);
   glLineWidth(2);
   glutSolidCube(1);
   glLineWidth(1);
   glPopMatrix();

   /**Wheels**/
   glPushMatrix();
   glTranslatef(-4+2.1+a1-gfPosXC,0.5,1+b1);
   glColor3f(0,0,0);
   glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(2.1+a1-gfPosXC,0.5,1+b1);
  glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-4+2.1+a1-gfPosXC,0.5,-1+b1);
   glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(2.1+a1-gfPosXC,0.5,1+b1);
  glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();



	gfPosXB += gfDeltaXC;
        if (gfPosXB >= 90.0 || gfPosXC <= 0.0) {
            gfPosXB = 0.0;
        }
	//glPopMatrix();
	glFlush();

}
void enemyCar2(GLfloat a2, GLfloat b2){
    glFlush();

     glPushMatrix();
    glColor3f(1,.8,0.8);
    glTranslatef(a2-gfPosXC,1,b2);
    glScalef(5,.6,2);
   glutSolidCube(1);
   glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
   glTranslatef(a2-gfPosXC,1.5,b2);
   glScalef(2,0.6,1.8);
   glLineWidth(2);
   glutSolidCube(1);
   glLineWidth(1);
   glPopMatrix();
/**wheels**/
   glPushMatrix();
   glTranslatef(-4+2.1+a2-gfPosXC,0.5,1+b2);
   glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(2.1+a2-gfPosXC,0.5,1+b2);
  glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-4+2.1+a2-gfPosXC,0.5,-1+b2);
   glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(2.1+a2-gfPosXC,0.5,-1+b2);
  glRotatef(pos_x,0,0,1);
   glutWireTorus(0.2,0.33,24,12);
   glPopMatrix();


	gfPosXC += gfDeltaXC;
        if (gfPosXC >= 100.0 || gfPosXC <= 0.0) {
            gfPosXC = 0.0;
        }

	glFlush();


}

void display1(void){/**Start menu**/
    glFlush();
	glClearColor(1.0,1.0,0.1,1.0);
    glPushMatrix();
	glColor3f(0,0,0);
    glTranslatef(-5.3+-2.5,5,-4);
    glRotatef(-90,0,1,0);
	glScalef(.01,.01,.01);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'4');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'X');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'4');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'R');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'A');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'L');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'L');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'Y');
	glPopMatrix();


	 glPushMatrix();
	glColor3f(0,0,0);
    glTranslatef(-5.3+-2.5,3,-4);
    glRotatef(-90,0,1,0);
	glScalef(.003,.003,.003);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'H');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'I');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'T');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'S');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'p');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'a');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'c');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'B');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'a');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'T');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'o');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'E');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'N');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'T');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'E');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'R');
	glPopMatrix();


	 glPushMatrix();
	glColor3f(0,0,0);
    glTranslatef(-5.3+-2.5,2.5,-4);
    glRotatef(-90,0,1,0);
	glScalef(.003,.003,.003);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'P');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'"');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'S');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'"');
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'T');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'o');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'S');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'t');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'a');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'t');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'R');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'a');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'c');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'e');
	glPopMatrix();


	 glPushMatrix();
	glColor3f(0,0,0);
    glTranslatef(-5.3+-2.5,2,-4);
    glRotatef(-90,0,1,0);
	glScalef(.003,.003,.003);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'P');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'"');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'Q');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'"');
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'T');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'o');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'Q');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'u');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'i');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'t');

	glPopMatrix();






 	 glPushMatrix();
	glColor3f(0,0,0);
    glTranslatef(-5.3+-2.5,1.5,-4);
    glRotatef(-90,0,1,0);
	glScalef(.003,.003,.003);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'P');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'z');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'-');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'x');
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'-');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'c');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'T');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'o');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'C');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'h');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'a');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'n');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'g');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');

	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'C');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'a');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'m');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'a');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)' ');
	glPopMatrix();

	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();

}

void display3(){/**Game over screen**/
    glFlush();
    glLineWidth(5);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glColor3f(0,0,0);
	glTranslated(0,0,0);
	glScaled(.5,.5,0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'G');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'A');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'M');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'E');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'O');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'V');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'E');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)'R');
	glPopMatrix();

	glutSwapBuffers();
	glFlush();
}
void display(void){


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
if(exit1==-1){
    display1();
}
if(exit1==0){
    DrawGround();
    car();
    track();
    sideBars();
    buildings();
    house();
    tree3(23,-14);
    tree3(15,14);
    tree3(40,-10);
    tree3(45,17);
    tree3(48,-14);
    tree3(35,17);
    tree3(17,10);
    tree3(32,-14);
    tree3(17,-10);
    tree3(26,-17);
    tree3(11,11);
    tree3(14,14);
    tree3(18,11);
    tree3(20,20);
    tree3(24,16);
    tree3(30,14);
    tree3(35,11);
    tree3(55,10);
    tree3(60,9);
    tree3(11,-11);
    tree3(14,-14);
    tree3(18,-11);
    tree3(20,-20);
    tree3(24,-16);
    tree3(30,-14);
    tree3(35,-11);
    tree3(55,-10);
    tree3(60,-9);

    enemyCar1(16, -3);
    enemyCar1(96, 0);
    enemyCar1(36, 0);
    enemyCar1(46, -3);
    enemyCar2(65, -3);
    enemyCar2(95, 3);
    enemyCar2(6, 3);
    enemyCar2(56, 3);
    enemyCar2(73, 0);






    glutSwapBuffers();
}
if(pos_x<-6||pos_x>6){
    exit1=1;
    display3();
    glutSwapBuffers();
}

}






void keyboards(unsigned char keys,int x4,int y4){

	if(keys==' '){
	    exit1=0;
        display();

	}

	//to quit
    if(keys=='q'||keys=='Q')
	{
		 exit(-1);

	}


	//to start
	if(keys=='s'||keys=='S')
    {
		glutIdleFunc(display);

    }
	//camera
	if(keys=='z'||keys=='Z')
	{
		 gluLookAt(-5,0,-3,15,-16,0,0,1,0);
	}

	if(keys=='x'||keys=='X')
	{
		 gluLookAt(-20,6,0,0,0,0,0,1,0);
	}

	if(keys=='c'||keys=='C')
	{
	  gluLookAt(-5,0,-3,-15,-16,0,0,1,0);
	}


	glutPostRedisplay();


}
void dropmenu(int keys){
	  keyboards((unsigned char) keys,0,0);
}

void delay(float secs)
{
	float end = clock()/CLOCKS_PER_SEC + secs;
	while((clock()/CLOCKS_PER_SEC) < end);
}
void fog(int value){
     glClearColor(.8,.8,.8,1);
    glEnable (GL_FOG); //enable the fog
glFogi (GL_FOG_MODE, GL_EXP2); //set the fog mode to GL_EXP2
glFogfv (GL_FOG_COLOR, fogColor); //set the fog color to our color chosen above
glFogf (GL_FOG_DENSITY, density); //set the density to the value above
glHint (GL_FOG_HINT, GL_NICEST); // set the fog to look the nicest, may slow down on older cards

}

void defog(int value){
 glDisable(GL_FOG);
  glClearColor(1,1,.5,1);

}
void init(){
    glClearColor(1,1,.5,1);
    glShadeModel(GL_SMOOTH);
    GLfloat light_diffuse[] = {0.8,0.7,1.0,1.0};
    glLightfv(GL_LIGHT0 , GL_DIFFUSE , light_diffuse);

    GLfloat light_position[] = {0.5 ,1.5 ,-2.0 ,0.0};
    glLightfv(GL_LIGHT0 , GL_POSITION , light_position);

    glEnable(GL_LIGHT0);

glEnable(GL_DIFFUSE);
    glEnable (GL_DEPTH_TEST); //enable the depth testing

    glMatrixMode(GL_PROJECTION);
    gluPerspective(400.0,1.5,1.0,50.0);
    gluLookAt(-20,6,0,0,0,0,0,1,0);
    glutKeyboardFunc(keyboards);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Gehan's 4X4 RALLY::MUD MANIA");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    init();
    glutTimerFunc(30000,fog,12);
    glutTimerFunc(45000,defog,12);
    glutMainLoop();


    return 0;
}
