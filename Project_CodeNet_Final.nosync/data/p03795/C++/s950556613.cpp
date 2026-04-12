#include<stdio.h>

int main(){
	int N, x, y;
	scanf("%d", &N);
	
	x = N*800;
	y = (N/15)*200;
	
	printf("%d", x-y);
}