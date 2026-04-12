#include<stdio.h>
int main(){
	int N=1-100, M=1-100;
	scanf("%d", &N);
	scanf("%d", &M);
	
	if(N==M){
		printf("Yes");
	}else if(N!=M){
		printf("No");
	}
	
	return 0;
}