#include<stdio.h>
#include<string.h>

int main()
{
	char S[5];
	scanf("%s", S);
	int i;
	for(i=0;i<strlen(S)-1;i++)
		if (S[i]=='A'&&S[i+1]=='C')
		{
			printf("Yes");
			return 0;
		}
	printf("No");
	return 0;
}