#include<stdio.h>
int main()
{
	char sta[3];
	scanf("%s",&sta);
	char c=sta[0];
	int i=0,flag=1;
	for( i=1;i<3;i++)
	{
		if(sta[i]!=c)
		{
			flag++;
		}
	}
	if(flag>1)
		printf("Yes");
	else
		printf("No");
	return 0;
 } 