//
// Created by andreimerfu on 28.05.2017.
//

#include "ForestView.h"

#define TREE_NUMBERS 300

GLfloat ambiente[] = {0.0,  	0.05, 0.0 };
GLfloat difuse[] = {0.4, 	0.5, 0.4};
GLfloat speculare[] = { 0.04, 0.9, 0.04, 1.0 };
GLfloat shininess[] = { .078125 };
//GLfloat shininess[] = { 25 };
//GLfloat shininess_mat[] = { 25 };



double trans_x[TREE_NUMBERS] ;
double trans_z[TREE_NUMBERS] ;

void initialize_trans_x_y(){
    for(int i = 0 ; i < TREE_NUMBERS ; i ++){
        trans_x[i] = rand() % 49 + (-29);
        trans_z[i] = rand() % 49 + (-29);
    }
}


void drawATree(){


    glPushMatrix();
    glColor3d(0.8,0.5,0.05);
    glRotated(-90.0,1.0,0.0,0.0);
    glTranslated(2.0,0.0,0.0);
    glutSolidCone(0.1,1.5,10,10);

    glPopMatrix();


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, speculare);
    glMaterialf(GL_FRONT, GL_SHININESS, (GLfloat) (shininess[0] * 128.0));

   // glColor3d(0.0,0.7,0.0);

    glPushMatrix();
    glTranslated(2.0,1.5,0.0);
    glutSolidSphere(0.5,15,15);

    glPopMatrix();

    glPushMatrix();
    glTranslated(1.8,1.8,-0.5);
    glutSolidSphere(0.5,15,15);

    glPopMatrix();

    glPushMatrix();
    glTranslated(2.2,1.8,-0.4);
    glutSolidSphere(0.5,15,15);

    glPopMatrix();


    glPushMatrix();
    glTranslated(1.8,1.8,0.3);
    glutSolidSphere(0.5,15,15);

    glPopMatrix();



    glPushMatrix();
    glTranslated(2.05,1.9,0.1);
    glutSolidSphere(0.5,15,15);

    glPopMatrix();

    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);

}

void drawAFir(){
    //glColor3d(0.0,0.5,0.0);


    glColor3d(0.8,0.5,0.05);

    glPushMatrix();
    glRotated(-90.0,1.0,0.0,0.0);
    glutSolidCylinder(0.1,0.5,10,10);

    glPopMatrix();

    glPushMatrix();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, speculare);
    glMaterialf(GL_FRONT, GL_SHININESS, (GLfloat) (shininess[0] * 128.0));


    glPushMatrix();


    glRotated(-90.0,1.0,0.0,0.0);
    glTranslated(0.0,0.0,1.5);
    glutSolidCone(0.5,0.8,15,15);

    glPopMatrix();


    glPushMatrix();


    glRotated(-90.0,1.0,0.0,0.0);
    glTranslated(0.0,0.0,1.0);
    glutSolidCone(0.5,1.0,15,15);

    glPopMatrix();


    glPushMatrix();


    glRotated(-90.0,1.0,0.0,0.0);
    glTranslated(0.0,0.0,0.5);
    glutSolidCone(0.5,1.0,15,15);

    glPopMatrix();




    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);

    glPopMatrix();

}

void drawAForest(){

    for(int i = 0 ; i < TREE_NUMBERS ; i ++)
    {

        glPushMatrix();
        if(trans_x[i] < -3 || trans_x[i] > 3 )
            glTranslated(trans_x[i],0.0 ,trans_z[i]);

        drawAFir();

        glPopMatrix();
    }


  //  drawATree();
}