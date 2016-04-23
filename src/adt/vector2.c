#include "adt/vector2.h"
#include <stdlib.h>
#include <math.h>
//MallocFunctions//
Clim_vector2i *mallocvec2i(int ox, int oy){
	Clim_vector2i* obj = (Clim_vector2i*)malloc(sizeof(Clim_vector2i));
	obj->x = ox;
	obj->y = oy;
	return obj;
}
Clim_vector2u *mallocvec2u(unsigned int ox, unsigned int oy){
	Clim_vector2u* obj = (Clim_vector2u*)malloc(sizeof(Clim_vector2u));
	obj->x = ox;
	obj->y = oy;
	return obj;
}
Clim_vector2f *mallocvec2f(float ox,float oy){
	Clim_vector2f* obj = (Clim_vector2f*)malloc(sizeof(Clim_vector2f));
	obj->x = ox;
	obj->y = oy;
	return obj;
}
Clim_vector2c *mallocvec2c(char ox,char oy){
	Clim_vector2c* obj = (Clim_vector2c*)malloc(sizeof(Clim_vector2c));
	obj->x = ox;
	obj->y = oy;
	return obj;
}
Clim_vector2g *mallocvec2g(void *ox, void *oy){
	Clim_vector2g* obj = (Clim_vector2g*)malloc(sizeof(Clim_vector2g));
	obj->x = ox;
	obj->y = oy;
	return obj;
}

//Addition functions//
void addVec2i(Clim_vector2i *out, const Clim_vector2i *a, const Clim_vector2i *b){
    out->x = a->x + b->x;
    out->y = a->y + b->y;
}
void addVec2u(Clim_vector2u *out, const Clim_vector2u *a, const Clim_vector2u *b){
    out->x = a->x + b->x;
    out->y = a->y + b->y;
}
void addVec2f(Clim_vector2f *out, const Clim_vector2f *a, const Clim_vector2f *b){
    out->x = a->x + b->x;
    out->y = a->y + b->y;
}

//Subtractive functions//
void subVec2i(Clim_vector2i *out, const Clim_vector2i *a, const Clim_vector2i *b){
    out->x = a->x - b->x;
    out->y = a->y - b->y;
}
void subVec2u(Clim_vector2u *out, const Clim_vector2u *a, const Clim_vector2u *b){
    out->x = a->x - b->x;
    out->y = a->y - b->y;
}
void subVec2f(Clim_vector2f *out, const Clim_vector2f *a, const Clim_vector2f *b){
    out->x = a->x - b->x;
    out->y = a->y - b->y;
}

//Multiplicative functions//
void multVec2i(Clim_vector2i *out, const Clim_vector2i *a, const Clim_vector2i *b){
    out->x = a->x * b->x;
    out->y = a->y * b->y;
}
void multVec2u(Clim_vector2u *out, const Clim_vector2u *a, const Clim_vector2u *b){
    out->x = a->x * b->x;
    out->y = a->y * b->y;
}
void multVec2f(Clim_vector2f *out, const Clim_vector2f *a, const Clim_vector2f *b){
    out->x = a->x * b->x;
    out->y = a->y * b->y;
}

//Division functions//
//Caution, all disolve into a Vector2f, since dividing usually turns into decimal places.//
void divVec2i(Clim_vector2i *out, const Clim_vector2i *a, const Clim_vector2i *b){
    if(b->x ==0 || b->y ==0)
    {
      b->x =1;
      b->y =1;
    }

    out->x = a->x / b->x;
    out->y = a->y / b->y;
}
void divVec2u(Clim_vector2u *out, const Clim_vector2u *a, const Clim_vector2u *b){
    if(b->x ==0 || b->y ==0)
    {
      b->x =1;
      b->y =1;
    }

    out->x = a->x / b->x;
    out->y = a->y / b->y;
}
void divVec2f(Clim_vector2f *out, const Clim_vector2f *a, const Clim_vector2f *b){
    if(b->x ==0 || b->y ==0)
    {
      b->x =1.0f;
      b->y =1.0f;
    }

    out->x = a->x / b->x;
    out->y = a->y / b->y;
}

// magnitude functions

float magnitude2i(Clim_vector2i a){
	float x = a.x * a.x;
	float y = a.y * a.y;
	return sqrt(x+y);
}
float magnitude2u(Clim_vector2u a){
	float x = a.x * a.x;
	float y = a.y * a.y;
	return sqrt(x+y);
}
float magnitude2f(Clim_vector2f a){
	float x = a.x * a.x;
	float y = a.y * a.y;
	return sqrt(x+y);
}

//lerp functions//
void lerp2i(Clim_vector2i *out,const Clim_vector2i *a, const Clim_vector2i *b,const float percent){
  Clim_vector2i i, j,k;
  subVec2i(&i,b,a);
  j.x = percent/100;
  j.y = percent/100;
  multVec2i(&k,&i,&j);
  addVec2i(out,a,&k);
}
void lerp2f(Clim_vector2f* out, const Clim_vector2f *a,const Clim_vector2f *b,const float percent){
  Clim_vector2f i, j,k;
  subVec2i(&i,b,a);
  j.x = percent/100.0f;
  j.y = percent/100.0f;
  multVec2f(&k,&i,&j);
  addVec2f(out,a,&k);
}


//Min/Max Functions//

Clim_vector2i *Max2i(Clim_vector2i *a,Clim_vector2i *b){
    return ((magnitude2i(a) > magnitude2i(b)) ? a : b);
}
Clim_vector2u *Max2u(Clim_vector2u *a,Clim_vector2u *b){
    return ((magnitude2u(a) > magnitude2u(b)) ? a : b);
}
Clim_vector2f *Max2f(Clim_vector2f *a,Clim_vector2f *b){
    return ((magnitude2f(a) > magnitude2f(b)) ? a : b);
}
Clim_vector2i *Min2i(Clim_vector2i *a,Clim_vector2i *b){
    return ((magnitude2i(a) < magnitude2i(b)) ? a : b);
}
Clim_vector2u *Min2u(Clim_vector2u *a,Clim_vector2u *b){
    return ((magnitude2u(a) < magnitude2u(b)) ? a : b);
}
Clim_vector2f *Min2f(Clim_vector2f *a,Clim_vector2f *b){
    return ((magnitude2f(a) < magnitude2f(b)) ? a : b);
}
