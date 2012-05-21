#include <stdio.h>
/*
Tugas Grafkom 3D Meja
Triantoro Sulistio  10108469
Deni Ocktaviyan     10108502
Arif Rahman         10108485
Harya Gusdevi       10108480

IF-10
*/

#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>


void init(void){
    GLfloat mat_specular[] = { 1.0, 0.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 35.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position2[] = { -2.0, 1.0, 1.0, 0.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
     
     
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glLoadIdentity();
	gluLookAt(3.3,3.3,3.0,0.0,0.25,0.0,0.0,1.0,0.0);
	
	//teapot
	glPushMatrix();
    glScaled(0.2, 0.3, 0.2);
    glTranslated(0.5, 7.5, 0.5);
	glutSolidTeapot(2.5);
	glPopMatrix();
	
	
	//meja atas
    glPushMatrix();
    glScaled(0.5,0.05,0.5);
    glTranslated(0.0, 30.2, 0.0);
	glutSolidCube(7.0);
	glPopMatrix();
	
	glTranslatef(-0.2, 0.2, 0.0);
	glScaled(1.2, 0.25, 1.2);
	
	//kaki1
	glPushMatrix();
    glScaled(.2,3.0, .2);
    glTranslated(2, -1.9, 2);
	glutSolidCube(3.0);
	glPopMatrix();
	
	//kaki2
	glPushMatrix();
    glScaled(.2,3.0, .2);
    glTranslated(-20, -1.9, 2);
	glutSolidCube(3.0);
	glPopMatrix();
	
	//kaki3
	glPushMatrix();
    glScaled(.2,3.0, .2);
    glTranslated(2, -1.9, -20);
	glutSolidCube(3.0);
	glPopMatrix();
	
	//kaki3
	glPushMatrix();
    glScaled(.2,3.0, .2);
    glTranslated(-20, -1.9, -20);
	glutSolidCube(3.0);
	glPopMatrix();
	
	
	
    glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h){
	glViewport(0, 0 , (GLsizei) w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Tugas Grafkom 3D Kelompok 10");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
