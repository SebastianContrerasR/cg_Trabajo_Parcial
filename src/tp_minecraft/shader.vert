#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

uniform mat4 model;
uniform mat4 camMatrix;

out vec3 color;
out vec2 textCoord;

void main()
{
	gl_Position = camMatrix * model * vec4(aPos, 1.0f);
	color = aColor;
	textCoord = vec2(aTex.x, aTex.y);
}