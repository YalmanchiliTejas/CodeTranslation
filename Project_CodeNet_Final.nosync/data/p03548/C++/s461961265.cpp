#include<stdio.h>

int main(void){
	int X, Y, Z;
	do{
			scanf("%d%d%d", &X, &Y, &Z);
	}while(X < 1 || X > 100000 || Y < 1 || Y > 100000  || Z < 1 || Z > 100000 || Y + Z * 2 > X);

	printf("%d\n", (X - Z) / (Y + Z));

	return 0;
}