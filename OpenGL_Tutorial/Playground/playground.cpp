#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <glfw3.h>
GLFWwindow* window;

#include <glm.hpp>
using namespace glm;

int main(void)
{
	if (!glfwInit())	//GLFW �ʱ�ȭ
	{
		fprintf(stderr, "GLFW �ʱ�ȭ ����\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);	//4x ��Ƽ�������
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	//OpenGL 3.3�� ���
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);	// mac os ��
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	//���� opengl�� ������� �ʴ´�.

	//��â�� ����, OpenGL ���ؽ�Ʈ�� ����
	window = glfwCreateWindow(1024, 768, "Playground", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "GLFW �����츦 ���µ� �����߽��ϴ�. OpenGL ������ ���缭 �ٽ� �õ��غ�����.");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//glew �ʱ�ȭ
	glewExperimental = true;	//�ھ� ���������� ���� �ʿ���
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "GLEW �ʱ�ȭ ����\n");
		glfwTerminate();
		return -1;
	}

	//�ؿ���  Escape Ű�� �������� ���� ������ �� �ֵ��� �� ��.
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do
	{
		//�ƹ��͵� �׸��� �ʽ��ϴ�.

		//���۱�ü
		glfwSwapBuffers(window);
		glfwPollEvents();

	} //���� escŰ�� ���������� Ȥ�� â�� �������� üũ
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	glfwTerminate();

	return 0;
}