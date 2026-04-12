#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(void){
	int N;
	int A,B;
	int i;
	int cond, count;

	int list[1000];
 
 	scanf("%d", &N);

 	for(i=0; i < N; i++){
 		scanf("%d", &list[i]);
 	}

 	cond = list[0];
 	count = 1;
	for(i=1; i < N; i++){
		if(cond <= list[i]){
			count++;
			cond = list[i];
		}
	}

	printf("%d\n", count);
 
	return 0;
}