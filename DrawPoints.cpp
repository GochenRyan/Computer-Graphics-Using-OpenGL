#include <glut.h>
#include <stdio.h>
#include <math.h>

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);		//背景颜色
	glColor3f(0.0f, 0.0f, 0.0f);		//绘图颜色
	glPointSize(4.0);		//点的大小
	glMatrixMode(GL_PROJECTION);		//设置合适的矩阵
	glLoadIdentity();		
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);		
}

void myDisplay(void) {
		glClear(GL_COLOR_BUFFER_BIT);		//清屏
		glBegin(GL_POINTS);		//画独立的点
		glVertex2i(100, 50);
		glVertex2i(100, 130);
		glVertex2i(150, 130);
		glEnd();
		glFlush();		//送所有的输出到显示设备
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);		//初始化工具包		
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		//初始化显示模式：单个显示缓存、颜色由红绿蓝来指定
	glutInitWindowSize(640, 480);		//指定屏幕窗口的初始尺寸
	glutInitWindowPosition(100,150);		//窗口左上角在屏幕上相对于左上角的位置
	glutCreateWindow("My First Attempt");		//打开并显示屏幕窗口,标上标题

	glutDisplayFunc(myDisplay);		//注册回调函数
	myInit();		//必要的其他初始化工作

	glutMainLoop();		//进入循环
}