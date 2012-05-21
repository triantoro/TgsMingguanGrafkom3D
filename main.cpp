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
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glLoadIdentity();
	gluLookAt(3.3,3.3,3.0,0.0,0.25,0.0,0.0,1.0,0.0);
	
	//meja atas
    glPushMatrix();
    glScaled(0.5,0.05,0.5);
    glTranslated(0.0, 30.2, 0.0);
	glutWireCube(7.0);
	glPopMatrix();
	
	glTranslatef(-0.2, 0.2, 0.0);
	glScaled(1.2, 0.25, 1.2);
	
	//kaki1
	glPushMatrix();
    glScaled(.2,3.0, .2);
    glTranslated(2, -1.9, 2);
	glutWireCube(3.0);
	glPopMatrix();
	
	//kaki2
	glPushMatrix();
    glScaled(.2,3.0, .2);
    glTranslated(-20, -1.9, 2);
	glutWireCube(3.0);
	glPopMatrix();
	
	//kaki3
	glPushMatrix();
    glScaled(.2,3.0, .2);
    glTranslated(2, -1.9, -20);
	glutWireCube(3.0);
	glPopMatrix();
	
	//kaki3
	glPushMatrix();
    glScaled(.2,3.0, .2);
    glTranslated(-20, -1.9, -20);
	glutWireCube(3.0);
	glPopMatrix();
	
	
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
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Tugas Grafkom 3D Kelompok 10");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}