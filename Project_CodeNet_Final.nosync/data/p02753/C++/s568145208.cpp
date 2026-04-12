#include<stdio.h>

int main()
{
	char S[3];
	
	scanf("%s",S);
	
	if ( S[1]==S[2] && S[2]==S[0] && S[0]==S[1] ){
		printf("No");
		return 0;
	}
	printf("Yes");
	
	return 0;
}