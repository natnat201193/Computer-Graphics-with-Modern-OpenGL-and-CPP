// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#pragma once
#include "stdio.h"
#include <GL\glew.h>
#include <GLFW\glfw3.h>

class Window
{
public:
	Window();

	Window(GLint windowWidth, GLint windowHeight);

	GLint Initialise();

	GLint GetBufferWidth() { return BufferWidth; }
	GLint GetBufferHeight() { return BufferHeight; }

	bool GetShouldClose() { return glfwWindowShouldClose(MainWindow); }

	bool* GetKeys() { return Keys; }
	GLdouble GetXChange();
	GLdouble GetYChange();

	void SwapBuffers() { glfwSwapBuffers(MainWindow); }

	~Window();

private:
	GLFWwindow* MainWindow{ };

	GLint 
		Width{ },
		Height{ },
		BufferWidth{ },
		BufferHeight{ };

	bool Keys[1024]{ };

	GLdouble 
		LastX{ },
		LastY{ },
		XChange{ },
		YChange{ };

	bool MouseFirstMoved{ };

	void CreateCallbacks();
	static void HandleKeys(GLFWwindow* window, GLint key, GLint code, GLint action, GLint mode);
	static void HandleMouse(GLFWwindow* window, GLdouble xPos, GLdouble yPos);
};
