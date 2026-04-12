#include<stdio.h>
int main()
{
	char s[3]={0};
	int i,a=0,b=0;
	for(i=0;i<3;i++)
	{
		scanf("%c",&s[i]);
		if(s[i]=='A')
			a++;
		else 
			b++;
	}
	if(a==3||b==3)
		printf("No");
	else 
		printf("Yes");
	
}