#include<stdio.h>

int main(){
	
	char S[10];
	
	scanf("%s",&S);
	getchar();
	
	if(S[0]==S[1] && S[2]==S[1]){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
}	