#include<stdio.h>
int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	N>=1;
	N<=100;
	M>=0;
	M<= N;
	if(M==N){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
	return 0;
}