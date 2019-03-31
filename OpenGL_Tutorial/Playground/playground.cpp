#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <glfw3.h>
GLFWwindow* window;

#include <glm.hpp>
using namespace glm;

int main(void)
{
	if (!glfwInit())	//GLFW 초기화
	{
		fprintf(stderr, "GLFW 초기화 실패\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);	//4x 안티엘리어싱
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	//OpenGL 3.3을 사용
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);	// mac os 용
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	//옛날 opengl은 사용하지 않는다.

	//새창을 열고, OpenGL 컨텍스트를 생성
	window = glfwCreateWindow(1024, 768, "Playground", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "GLFW 윈도우를 여는데 실패했습니다. OpenGL 버젼을 낮춰서 다시 시도해보세요.");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//glew 초기화
	glewExperimental = true;	//코어 프로파일을 위해 필요함
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "GLEW 초기화 실패\n");
		glfwTerminate();
		return -1;
	}

	//밑에서  Escape 키가 눌러지는 것을 감지할 수 있도록 할 것.
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do
	{
		//아무것도 그리지 않습니다.

		//버퍼교체
		glfwSwapBuffers(window);
		glfwPollEvents();

	} //만약 esc키가 눌러졌는지 혹은 창이 닫혔는지 체크
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	glfwTerminate();

	return 0;
}