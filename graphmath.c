#include "graphmath.h"

#include <math.h>

vec2 point_projection(vec3 v3){
    float side = sqrtf(powf(v3.x, 2.0f) / 2.0f);
    if(v3.x < 0.0f) side *= -1.0f;
    return (vec2){v3.z - side, v3.y - side};
}

vec3 rotate(vec3 v3, vec3 theta){
    vec3 vp = (vec3){
        v3.x*cosf(theta.z)*cosf(theta.y) + v3.y*cosf(theta.z)*sinf(theta.y)*sinf(theta.x) - v3.y*sinf(theta.z)*cosf(theta.x) + v3.z*cosf(theta.z)*sinf(theta.y)*cosf(theta.x) + v3.z*sinf(theta.z)*sinf(theta.x),
        v3.x*sinf(theta.z)*cosf(theta.y) + v3.y*sinf(theta.z)*sinf(theta.y)*sinf(theta.x) + v3.y*cosf(theta.z)*cosf(theta.x) + v3.z*sinf(theta.z)*sinf(theta.y)*cosf(theta.x) - v3.z*cosf(theta.z)*sinf(theta.x),
        -v3.x*sinf(theta.y) + v3.y*cosf(theta.y)*sinf(theta.x) + v3.z*cosf(theta.y)*cosf(theta.x)
    };
    return vp;
}
