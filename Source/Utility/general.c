#include "../../Include/general.h"
#include <time.h>

void swapPointers(void *a,void *b){
	void *temp;
	temp = a;
	a = b;
	b = temp;

	}


const char *timeToString(){
		return ctime(time);
	}
