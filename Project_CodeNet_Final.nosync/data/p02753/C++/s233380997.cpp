#include<stdio.h>

int main(){
	
	char s[4];
	scanf("%s",&s);
	getchar();
	
	if(s[0] == s[1] && s[1] == s[2] && s[2] == s[0]){
		printf("No");
	}
	else{
		printf("Yes");
	}
	
	
	return 0;
}