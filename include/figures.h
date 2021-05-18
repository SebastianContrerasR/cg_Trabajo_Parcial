#ifndef __FIGURES_H__
#define __FIGURES_H__

class Cube {

	float   width;
	float   height;
	float   depth;
	float*  vertices;
	unsigned int* indices;

public:
	Cube(float width=1.0f, float height=1.0f, float depth=1.0f)
			: width(width), height(height), depth(depth),
				vertices(new float[16*8]), indices(new unsigned int[6*6]) {
		float wm = width / 2.0f;
		float hm = height / 2.0f;
		float dm = depth / 2.0f;
		float temp[] = {
			 // posiciones        colores          texturas
			-wm,  hm,  dm,   1.0f, 0.0, 0.0,   0.0f, 1.0f,  // 0
			 wm,  hm,  dm,   1.0f, 0.0, 0.0,   1.0f, 1.0f,  // 1
			-wm, -hm,  dm,   1.0f, 0.0, 0.0,   0.0f, 0.0f,  // 2
			 wm, -hm,  dm,   1.0f, 0.0, 0.0,   1.0f, 0.0f,  // 3
			-wm,  hm, -dm,   1.0f, 0.0, 0.0,   1.0f, 1.0f,  // 4
			 wm,  hm, -dm,   1.0f, 0.0, 0.0,   0.0f, 1.0f,  // 5
			-wm, -hm, -dm,   1.0f, 0.0, 0.0,   1.0f, 0.0f,  // 6
			 wm, -hm, -dm,   1.0f, 0.0, 0.0,   0.0f, 0.0f,  // 7

			-wm,  hm,  dm,   1.0f, 0.0, 0.0,   0.0f, 0.0f,  // 8
			 wm,  hm,  dm,   1.0f, 0.0, 0.0,   1.0f, 0.0f,  // 9
			-wm, -hm,  dm,   1.0f, 0.0, 0.0,   0.0f, 0.0f,  // 10
			 wm, -hm,  dm,   1.0f, 0.0, 0.0,   1.0f, 0.0f,  // 11
			-wm,  hm, -dm,   1.0f, 0.0, 0.0,   0.0f, 1.0f,  // 12
			 wm,  hm, -dm,   1.0f, 0.0, 0.0,   1.0f, 1.0f,  // 13
			-wm, -hm, -dm,   1.0f, 0.0, 0.0,   0.0f, 1.0f,  // 14
			 wm, -hm, -dm,   1.0f, 0.0, 0.0,   1.0f, 1.0f }; // 15
			/*-wm,  hm,  dm,   1.0f, 0.0, 0.0,   0.0f, 1.0f,  // 0
			 wm,  hm,  dm,   1.0f, 0.0, 0.0,   1.0f, 1.0f,  // 1
			-wm, -hm,  dm,   1.0f, 0.0, 0.0,   0.0f, 0.0f,  // 2
			 wm, -hm,  dm,   1.0f, 0.0, 0.0,   1.0f, 0.0f,  // 3
			-wm,  hm, -dm,   1.0f, 0.0, 0.0,   1.0f, 1.0f,  // 4
			 wm,  hm, -dm,   1.0f, 0.0, 0.0,   0.0f, 1.0f,  // 5
			-wm, -hm, -dm,   1.0f, 0.0, 0.0,   1.0f, 0.0f,  // 6
			 wm, -hm, -dm,   1.0f, 0.0, 0.0,   0.0f, 0.0f,  // 7

			-wm,  hm,  dm,   1.0f, 0.0, 0.0,   0.0f, 0.0f,  // 8
			 wm,  hm,  dm,   1.0f, 0.0, 0.0,   1.0f, 0.0f,  // 9
			-wm, -hm,  dm,   1.0f, 0.0, 0.0,   0.0f, 0.0f,  // 10
			 wm, -hm,  dm,   1.0f, 0.0, 0.0,   1.0f, 0.0f,  // 11
			-wm,  hm, -dm,   1.0f, 0.0, 0.0,   0.0f, 1.0f,  // 12
			 wm,  hm, -dm,   1.0f, 0.0, 0.0,   1.0f, 1.0f,  // 13
			-wm, -hm, -dm,   1.0f, 0.0, 0.0,   0.0f, 1.0f,  // 14
			 wm, -hm, -dm,   1.0f, 0.0, 0.0,   1.0f, 1.0f}; // 15
			 */
		for (unsigned int i = 0; i < 16*8; ++i) {
			vertices[i] = temp[i];
		}
		unsigned int temp2[] = {
			 0,  1,  2,   1,  2,  3,
			 8,  9, 12,   9, 12, 13,
			 1,  5,  3,   3,  5,  7,
			11, 14, 15,  10, 11, 14,
			 0,  4,  6,   0,  2,  6,
			 4,  5,  6,   5,  6,  7};
		for (unsigned int i = 0; i < 6*6; ++i) {
			indices[i] = temp2[i];
		}
	}
	~Cube() {
		delete[] vertices;
		delete[] indices;
	}
	float* getVertices() {
		return vertices;
	}
	unsigned int* getIndices() {
		return indices;
	}
	unsigned int getVSize() {
		return 16*8;
	}
	unsigned int getISize() {
		return 6*6;
	}
};

#endif