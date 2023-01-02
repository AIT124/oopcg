#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

void move(int j, int h, int &x, int &y){
    int initialx = x, initialy = y;
    if (j == 1) y -= h;
    else if (j == 2) x += h;
    else if (j == 3) y += h;
    else if (j == 4) y-= h;


    glBegin(GL_LINES);
    glColor3f(0.0,1.0,0.0);
        glVertex2f(x,y);
        glVertex2f(initialx, initialy);
    glEnd();
    glFlush();
}

void hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y){
    if (i > 0){
        i--;
        hilbert(d,r,u,l,i,h,x,y);
        move(r,h,x,y);

        hilbert(r,d,l,u,i,h,x,y);
        move(d,h,x,y);

        hilbert(r,d,l,u,i,h,x,y);
        move(l,h,x,y);

        hilbert(u,l,d,r,i,h,x,y);
    }
}

void display(){

    int x = 35, y = 35, h = 10, r =2, d = 3, l = 4, u = 1;
    hilbert(r,d,l,u,6,h,x,y);
}

void myInit(){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 700);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("HILBERT CURVE");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}





void hilbert(int r,int d,int l,int u,int i,int h,int &x,int&y){
    if(i>0){
        i--;
        hilbert(d,r,u,l,i,h,x,y);
        move(r,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(d,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(l,h,x,y);
        hilbert(u,l,d,r,i,h,x,y);


    }
}