#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

int a[600000],p1=300000,p2=300001,n;
using namespace std; 
int main()
{
	scanf("%d",&n);
	int dir=2;
	for(int i=0;i<n;i++)
	{
		dir=3-dir;
		if (dir==1)
		{
			scanf("%d",a+p2);
			p2++;
		}
		else
		{
			scanf("%d",a+p1);
			p1--;
		}
	}
	if (dir==2)
	{
		for(int i=p1+1;i<p2-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[p2-1]);
	}
		
	else
	{
		for(int i=p2-1;i>p1+1;i--)
			printf("%d ",a[i]);
		printf("%d\n",a[p1+1]);			
	}
		
	
	return 0;	
}