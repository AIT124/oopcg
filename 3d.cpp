/*

	Name : Puja
	Roll No : 7243
	
	Assignment : 3
	Problem Statement :
	Write C++ program to draw 3-D cube and perform following transformations on it using OpenGL.
	a) Scaling    b) Translation    c) Rotation about an axis(X-axis/ Y-axis/Z-axis)
	
*/
#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;


double const pi = 3.14159265359, ert = 180;
float ver[8][3] = 
{
    {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},
    {1.0,1.0,1.0},
    {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0},
    {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0},
};

GLfloat color[8][3] = 
{
    {0.0,0.0,0.0},
    {1.0,0.0,0.0},
    {1.0,1.0,0.0},
    {0.0,1.0,0.0},
    {0.0,0.0,1.0},
    {1.0,0.0,1.0},
    {1.0,1.0,1.0},
    {0.0,1.0,1.0},
};

void quad(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glVertex3fv(ver[a]);

    glColor3fv(color[b]);
    glVertex3fv(ver[b]);

    glColor3fv(color[c]);
    glVertex3fv(ver[c]);

    glColor3fv(color[d]);
    glVertex3fv(ver[d]);
    glEnd();
}

void colorcube()
{
    quad(0,3,2,1);
    quad(2,3,7,6);
    quad(0,4,7,3);
    quad(1,2,6,5);
    quad(4,5,6,7);
    quad(0,1,5,4);
}


int tx, ty, tz;
void translation(){
	cout << "Enter tx, ty, tz : "; cin >> tx >> ty >> tz;
	for (int i = 0;i < 8; i++)
		ver[i][0] += tx, ver[i][1] += ty, ver[i][2] += tz;
	glutPostRedisplay();
}


void rotation(){
	int ch;
	cout << "\n	1. X axis \n	2. Y axis \n	3. Z axis\nEnter your choice : "; cin >> ch;
	double theta;
	cout << "Enter theta :"; cin >> theta;
	theta = theta * pi/ert;
	
	if (ch == 1){
		for (int i = 0;i < 8; i++){
			int y = ver[i][1], z = ver[i][2] ;
			ver[i][1] = y*cos(theta) - z*sin(theta), ver[i][2] = y*sin(theta) + z*cos(theta);
		}	
	}
	if (ch == 2){
		for (int i = 0;i < 8; i++){
			int x = ver[i][0], z = ver[i][2] ;
			ver[i][2] = z*cos(theta) - x*sin(theta), ver[i][0] = z*sin(theta) + x*cos(theta);
		}
	}
	if (ch == 3){
		for (int i = 0;i < 8; i++){
			int x = ver[i][0], y = ver[i][1] ;
			ver[i][0] = x*cos(theta) - y*sin(theta), ver[i][1] = x*sin(theta) + y*cos(theta);
		}
	}
	
	glutPostRedisplay();
}

int sx, sy, sz;
void scaling(){
	cout << "Enter sx, sy, sz : "; cin >> sx >> sy >> sz;
	for (int i = 0;i < 8; i++)
		ver[i][0] *= sx, ver[i][1] *= sy, ver[i][2] *= sz;
	glutPostRedisplay();
	
}

void menu(){
	int choice;
	
		cout << "------MENU----\n";
		cout << "1. Translation\n2. Rotation\n3. Scaling\n :: ";
		cin >> choice;
		if (choice == 1)
			translation();
		else if (choice == 2)
			rotation();
		else if (choice == 3)
			scaling();
		else
			return;
	
}

void display()
{
    glClearColor( 0, 0, 0, 1 );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 60, w / h, 0.1, 100 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt
        ( 
        3, 3, 3, 
        0, 0, 0,
        0, 0, 1
        );

    colorcube();

    glutSwapBuffers();
    menu();
}



int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow( "GLUT" );
    glutDisplayFunc( display );
    glEnable( GL_DEPTH_TEST );
    glutMainLoop();
    return 0;
}
