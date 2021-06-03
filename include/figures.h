#ifndef __FIGURES_H__
#define __FIGURES_H__

struct RGB {
	float r, g, b;
};

class Object {

protected:
	float* vertices;
	unsigned int* indices;
	unsigned int  nv;
	unsigned int  ni;
	unsigned int  n;

public:
	Object(unsigned int n, unsigned int m)
			: vertices(new float[24*n]), indices(new unsigned int[m]), nv(24*n), ni(m), n(n) {}

	float* getVertices() {
		return vertices;
	}
	unsigned int* getIndices() {
		return indices;
	}
	unsigned int getVSize() {
		return nv;
	}
	unsigned int getISize() {
		return ni;
	}
	unsigned int len() {
		return sizeof(float)*n;
	}
	void* skip(unsigned int i) {
		return (void*)(i * sizeof(unsigned int));
	}
};

class Cube : public Object {
	glm::vec3 scale;
public:
	Cube(
		glm::vec3 scale = glm::vec3(1.0f),
		RGB a = { 1.0f, 1.0f, 1.0f },  // Top
		RGB b = { 1.0f, 1.0f, 0.0f },  // Bottom
		RGB c = { 1.0f, 0.0f, 0.0f },  // Front
		RGB d = { 1.0f, 0.5f, 0.0f },  // Back
		RGB e = { 0.0f, 1.0f, 0.0f },  // Left
		RGB f = { 0.0f, 0.0f, 1.0f }   // Right
	) :
		Object(11, 6 * 6),
		scale(scale) {
		glm::vec3 half = scale * 0.5f;

		float vTemp[] = {
			//        Positions       |||    Colors    |||       Normals      |||     Textures
			// Top
			 half.x,  half.y, -half.z,   a.r, a.g, a.b,    0.0f,  1.0f,  0.0f,   1.0f, 1.0f,  //  0
			-half.x,  half.y, -half.z,   a.r, a.g, a.b,    0.0f,  1.0f,  0.0f,   0.0f, 1.0f,  //  1
			-half.x,  half.y,  half.z,   a.r, a.g, a.b,    0.0f,  1.0f,  0.0f,   0.0f, 0.0f,  //  2
			 half.x,  half.y,  half.z,   a.r, a.g, a.b,    0.0f,  1.0f,  0.0f,   1.0f, 0.0f,  //  3
			// Bottom
			 half.x, -half.y,  half.z,   b.r, b.g, b.b,    0.0f, -1.0f,  0.0f,   1.0f, 1.0f,  //  4
			-half.x, -half.y,  half.z,   b.r, b.g, b.b,    0.0f, -1.0f,  0.0f,   0.0f, 1.0f,  //  5
			-half.x, -half.y, -half.z,   b.r, b.g, b.b,    0.0f, -1.0f,  0.0f,   0.0f, 0.0f,  //  6
			 half.x, -half.y, -half.z,   b.r, b.g, b.b,    0.0f, -1.0f,  0.0f,   1.0f, 0.0f,  //  7
			// Front
			 half.x,  half.y,  half.z,   c.r, c.g, c.b,    0.0f,  0.0f,  1.0f,   1.0f, 1.0f,  //  8
			-half.x,  half.y,  half.z,   c.r, c.g, c.b,    0.0f,  0.0f,  1.0f,   0.0f, 1.0f,  //  9
			-half.x, -half.y,  half.z,   c.r, c.g, c.b,    0.0f,  0.0f,  1.0f,   0.0f, 0.0f,  // 10
			 half.x, -half.y,  half.z,   c.r, c.g, c.b,    0.0f,  0.0f,  1.0f,   1.0f, 0.0f,  // 11
			// Back
			-half.x,  half.y, -half.z,   d.r, d.g, d.b,    0.0f,  0.0f, -1.0f,   1.0f, 1.0f,  // 12
			 half.x,  half.y, -half.z,   d.r, d.g, d.b,    0.0f,  0.0f, -1.0f,   0.0f, 1.0f,  // 13
			 half.x, -half.y, -half.z,   d.r, d.g, d.b,    0.0f,  0.0f, -1.0f,   0.0f, 0.0f,  // 14
			-half.x, -half.y, -half.z,   d.r, d.g, d.b,    0.0f,  0.0f, -1.0f,   1.0f, 0.0f,  // 15
			// Left
			-half.x,  half.y,  half.z,   e.r, e.g, e.b,   -1.0f,  0.0f,  0.0f,   1.0f, 1.0f,  // 16
			-half.x,  half.y, -half.z,   e.r, e.g, e.b,   -1.0f,  0.0f,  0.0f,   0.0f, 1.0f,  // 17
			-half.x, -half.y, -half.z,   e.r, e.g, e.b,   -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,  // 18
			-half.x, -half.y,  half.z,   e.r, e.g, e.b,   -1.0f,  0.0f,  0.0f,   1.0f, 0.0f,  // 19
			// Right
			 half.x,  half.y, -half.z,   f.r, f.g, f.b,    1.0f,  0.0f,  0.0f,   1.0f, 1.0f,  // 20
			 half.x,  half.y,  half.z,   f.r, f.g, f.b,    1.0f,  0.0f,  0.0f,   0.0f, 1.0f,  // 21
			 half.x, -half.y,  half.z,   f.r, f.g, f.b,    1.0f,  0.0f,  0.0f,   0.0f, 0.0f,  // 22
			 half.x, -half.y, -half.z,   f.r, f.g, f.b,    1.0f,  0.0f,  0.0f,   1.0f, 0.0f,  // 23
		};
		unsigned int iTemp[] = {
			 0,  1,  2,    0,  2,  3,  // Top
			 4,  5,  6,    4,  6,  7,  // Bottom
			 8,  9, 10,    8, 10, 11,  // Front
			12, 13, 14,   12, 14, 15,  // Back
			16, 17, 18,   16, 18, 19,  // Left
			20, 21, 22,   20, 22, 23   // Right
		};

		for (unsigned int i = 0; i < 11 * 24; i++)
			vertices[i] = vTemp[i];
		for (unsigned int i = 0; i < 6 * 6; i++)
			indices[i] = iTemp[i];
	}
};

#endif
