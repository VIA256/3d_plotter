#include "graphmath.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef __WIN32
	#define __USE_XOPEN /* required for useconds_t */
	#include <unistd.h>
	int usleep(useconds_t usec);
	#define CROSS_SLEEP(ms) usleep(ms * 1000)
	#define CLEAR_CONSOLE() system("clear")
#else
	#include <windows.h>
	#define CROSS_SLEEP(ms) Sleep(ms)
	#define CLEAR_CONSOLE() system("cls")
#endif

int main(void){
    const size_t s_points = 8;
    const float cl = 3.0f;
    vec3 points[8] = {
        (vec3){cl, cl, cl},//CUBE
        (vec3){cl, -cl, cl},
        (vec3){cl, -cl, -cl},
        (vec3){cl, cl, -cl},
        (vec3){-cl, cl, cl},
        (vec3){-cl, -cl, cl},
        (vec3){-cl, -cl, -cl},
        (vec3){-cl, cl, -cl},
        /*(vec3){0.0f, cl, 0.0f},//TRIANGLE
        (vec3){0.0f, -cl, -cl},
        (vec3){0.0f, -cl, cl},*/
        /*(vec3){cl, cl, 0.0f},//TETRAHEDRON
        (vec3){cl, -cl, -cl},
        (vec3){cl, -cl, cl},
        (vec3){-cl, 0.0f, 0.0f},*/
    };
    
    vec3 theta = (vec3){0.0f, 0.0f, 0.0f};
    
    vec2 v2;
    vec3 v3;
    char c;
    const int width = 20*2;
    const int height = 20*2;
    while(1){
    for(int y = height/2; y >= -height/2; --y){
        for(int x = -width/2; x <= width/2; ++x){
           c = ' ';
           for(size_t i = 0; i < s_points; ++i){
               v3 = rotate(points[i], theta);
               v2 = point_projection(v3);
               if(
                   lroundf(v2.x) == x &&
                   lroundf(v2.y) == y
                   ) c = '#';
           }
           putchar(c);
        }
        putchar('\n');
    }
//    while(getchar() != '\n');
		CROSS_SLEEP(40);
    CLEAR_CONSOLE();
    theta.z += 3.1415926535f / 24.0f;
    theta.y += 3.1415926535f / 23.0f;
    theta.x += 3.1415926535f / 25.0f;
    if(theta.z >= 3.1415926535f * 2.0f) theta.z = 0.0f;
    if(theta.y >= 3.1415926535f * 2.0f) theta.y = 0.0f;
    if(theta.x >= 3.1415926535f * 2.0f) theta.x = 0.0f;
    }
    
    return 0;
}



