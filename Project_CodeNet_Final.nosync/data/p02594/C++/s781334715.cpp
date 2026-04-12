#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>

int main(){
	int a;
	
	if(scanf("%d", &a))
	{
		printf("%s", a >= 30 ? "Yes" : "No");
	}
	return 0;
}


