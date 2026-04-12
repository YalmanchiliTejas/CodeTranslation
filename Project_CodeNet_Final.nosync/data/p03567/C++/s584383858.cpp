#include<stdio.h>
int main()
{
	char a[10];
	int lose=0;
	scanf("%s",a);
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='A'&&a[i+1]=='C')
		{
			lose=1;
			break;
		}
	}
	if(lose)
		printf("Yes\n");
	else
		printf("No\n"); 
	
}