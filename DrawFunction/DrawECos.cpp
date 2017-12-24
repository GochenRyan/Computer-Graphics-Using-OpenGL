#include <glut.h>
#include <stdio.h>
#include <math.h>

const int screenWidth = 640;		//屏幕窗口的宽度
const int screenHeight = 480;		//屏幕窗口的高度
GLdouble A, B, C, D;		//比例变换和平移

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);		//背景颜色为白
	glColor3f(0.0f, 0.0f, 0.0f);		//绘图颜色为黑
	glPointSize(2.0);		//点的大小为2x2像素
	glMatrixMode(GL_PROJECTION);		//设置合适的矩阵，“相机形状”
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
	A = screenWidth / 4.0;
	B = 0.0;
	C = D = screenHeight / 2.0;
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);		//清屏
	glBegin(GL_POINTS);		//画独立的点
	for (GLdouble x = 0.0; x < 4.0; x += 0.005) {
		GLdouble func = exp(-x) * cos(2 * 3.14159265 * x);
		glVertex2d(A * x + B, C * func + D);		//X方向缩放A，平移B个像素；Y方向缩放C，平移D个像素
	}
	glEnd();
	glFlush();		//送所有的输出到显示设备
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);		//初始化工具包		
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		//初始化显示模式：单个显示缓存、颜色由红绿蓝来指定
	glutInitWindowSize(screenWidth, 480);		//指定屏幕窗口的初始尺寸
	glutInitWindowPosition(100, 150);		//窗口左上角在屏幕上相对于左上角的位置
	glutCreateWindow("My First Attempt");		//打开并显示屏幕窗口,标上标题

	glutDisplayFunc(myDisplay);		//注册回调函数
	myInit();		//必要的其他初始化工作

	glutMainLoop();		//进入循环
}