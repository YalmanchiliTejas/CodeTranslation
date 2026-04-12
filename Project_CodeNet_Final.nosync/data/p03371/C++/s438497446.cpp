#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a,b,c,x,y;
int ans=2e9;
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	for(int i=0;i<=max(x,y);i++)
	{
		int rx=x-i,ry=y-i;
		if(rx<0)rx=0;
		if(ry<0)ry=0;
		ans=min(ans,i*2*c+rx*a+ry*b);
	}
	printf("%d",ans);
	return 0;
} 