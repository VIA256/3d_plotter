#ifndef GRAPHMATH_H
#define GRAPHMATH_H

typedef struct{
	float x;
	float y;
} vec2;

typedef struct{
	float x;
	float y;
	float z;
} vec3;

vec2 point_projection(vec3 v3);
vec3 rotate(vec3 v3, vec3 theta);

#endif
