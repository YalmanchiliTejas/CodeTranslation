#include<stdio.h>
#include<string.h>

int main()
{
	char S[3];
	
	scanf("%s", S);
	
	if(S[0]==S[1] && S[1]==S[2]) printf("No");
	else printf("Yes");
	
	return 0;
}

