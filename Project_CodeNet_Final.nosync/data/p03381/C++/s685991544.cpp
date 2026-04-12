#include<bits/stdc++.h>
using namespace std;
int a,b,c,i,j,k;
int x[200005];
int y[200005];
main()
{
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%d",&x[i]);
		y[i]=x[i];
	}
	sort(x,x+a+1);
	for(i=1;i<=a;i++)
	{	//printf("%d")
		if(y[i]>x[a/2])
		{
			printf("%d\n",x[a/2]);
		}
		else
		{
			printf("%d\n",x[a/2+1]);
		}
	}
}