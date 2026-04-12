
#include<stdio.h>
int main(void)
{
	int n,h[20];
	int highest=0;
	int num=1;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&h[i]);	
	}
	highest=h[0];
	for (int i=1;i<n;i++)
	{
		if(highest<=h[i])
		{
			highest=h[i];
			num++;
		}
	}
	printf("%d",num);
}