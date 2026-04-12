#include<stdio.h>
#include<string.h>
int main()
{
	char s[10];
	scanf("%s",s);
	int flag=0;
	for(int i=0;i<strlen(s)-1;i++)
		if(s[i]=='A' && s[i+1]=='C')
			flag=1;
	if(flag)
		printf("Yes");
	else
		printf("No");
	printf("\n");
	return 0;
 } 