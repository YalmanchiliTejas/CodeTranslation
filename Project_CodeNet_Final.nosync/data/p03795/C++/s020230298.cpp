#include <stdio.h>

int main (void){
	int N;
	scanf("%d",&N);
	printf("%d\n", 800*N-200*(int)(N/15));
	return 0;
}