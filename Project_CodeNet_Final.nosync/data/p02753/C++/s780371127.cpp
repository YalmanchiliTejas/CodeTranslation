#include<stdio.h>
#include<string.h>
int main()
{
	char s[3];
	scanf("%s",&s);
	int m=0,n=0;
	int len = strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]=='A')
			m++;
		if(s[i]=='B')
			n++;
	}
	if(m&&n)
		printf("Yes");
	else printf("No");
	return 0;
 } 