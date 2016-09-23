#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void display(void)
{
	static GLubyte Mask[128];
	FILE *fp;
	fp = fopen("mask.bmp", "rb");
	if (!fp)
		exit(0);

	if (fseek(fp, -(int)sizeof(Mask), SEEK_END))
		exit(0);

	if (!fread(Mask, sizeof(Mask), 1, fp))
		exit(0);

	fclose(fp);

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 1.0f);
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(Mask);
	glRectf(-0.5f, -0.5f, 0.0f, 0.0f);   // 在左下方绘制一个有镂空效果的正方形
	glDisable(GL_POLYGON_STIPPLE);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(0.0f, 0.0f, 0.5f, 0.5f);     // 在右上方绘制一个无镂空效果的正方形
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