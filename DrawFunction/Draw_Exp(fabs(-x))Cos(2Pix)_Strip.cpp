#include <glut.h>
#include <stdio.h>
#include <cmath>

const int W = 640;
const int H = 480;
GLdouble A, B, C, D;

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);		//背景颜色为白
	glColor3f(0.0f, 0.0f, 0.0f);		//绘图颜色为黑
	glPointSize(2.0);		//点的大小为2x2像素
	glMatrixMode(GL_PROJECTION);		//设置合适的矩阵，“相机形状”
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)W, 0.0, (GLdouble)H);
	A = W / 2.0;
	B = W / 2.0;
	C = H / 6.0;
	D = H / 2.0;
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);		//清屏
	glBegin(GL_LINE_STRIP);		//画独立的点
	for (GLdouble x = -1; x < 1; x += 0.005) {
		//printf("%f\n", fabs(-x));
		GLdouble func = exp(fabs(-x)) * cos(2 * 3.14159265 * x);
		glVertex2d(A * x + B, C * func + D);		//X方向缩放A，平移B个像素；Y方向缩放C，平移D个像素
	}
	glEnd();
	glFlush();		//送所有的输出到显示设备
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);		//初始化工具包		
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		//初始化显示模式：单个显示缓存、颜色由红绿蓝来指定
	glutInitWindowSize(W, H);		//指定屏幕窗口的初始尺寸
	glutInitWindowPosition(100, 150);		//窗口左上角在屏幕上相对于左上角的位置
	glutCreateWindow("exp|-x|*cos(2*Pi*x)");		//打开并显示屏幕窗口,标上标题

	glutDisplayFunc(myDisplay);		//注册回调函数
	myInit();		//必要的其他初始化工作

	glutMainLoop();		//进入循环
}