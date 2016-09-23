#include <GL/glut.h>
#include <math.h>
const int n = 20;
const GLfloat R = 0.5f;
const GLfloat Pi = 3.1415926536f;

void display(void)
{
	GLfloat a = 1 / (2 - 2 * cos(72 * Pi / 180));
	GLfloat bx = a * cos(18 * Pi / 180);
	GLfloat by = a * sin(18 * Pi / 180);
	GLfloat cy = -a * cos(18 * Pi / 180);
	GLfloat
		PointA[2] = { 0, a },
		PointB[2] = { bx, by },
		PointC[2] = { 0.5, cy },
		PointD[2] = { -0.5, cy },
		PointE[2] = { -bx, by };
	glClear(GL_COLOR_BUFFER_BIT);
	//glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glBegin(GL_LINE_LOOP);
		glVertex2fv(PointA);
		glVertex2fv(PointC);
		glVertex2fv(PointE);
		glVertex2fv(PointB);
		glVertex2fv(PointD);
	glEnd();
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("the first OpenGL program!");
	glutDisplayFunc(&display);
	glutMainLoop();

	return 0;
}