#include<stdio.h>

int main(){
	
	int N;
	int M;
	scanf("%d %d",&N,&M);
	
	
	
	if(N>100 || N<=0 || M<0 || M>N){
		printf("eror\n");
	}
	else if(N==M){
		printf("Yes");
	}
	else if(N>=M || N<=M){
		printf("No");
	}

	
	
	
	
	return 0;
}