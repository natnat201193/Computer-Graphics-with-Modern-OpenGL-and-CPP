// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <GLFW\glfw3.h>

class Camera
{
public:
	Camera();
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);

	void KeyControl(bool* keys, GLdouble deltaTime);
	void MouseControl(GLdouble xChange, GLdouble yChange);

	glm::vec3 GetCameraPosition();
	glm::vec3 GetCameraDirection();

	glm::mat4 CalculateViewMatrix();

	~Camera();

private:
	glm::lowp_dvec3
		Position{ },
		Front{ },
		Up{ },
		Right{ },
		WorldUp{ };

	GLdouble 
		Yaw{ },
		Pitch{ },
		MoveSpeed{ },
		TurnSpeed{ };

	void Update();
};
