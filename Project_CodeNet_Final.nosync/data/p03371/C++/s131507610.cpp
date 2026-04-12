#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>

using namespace std;
int a,b,c,x,y,ans;
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	if(2*c<a+b)
	{
		while(x>=1&&y>=1)
		{
			ans+=c*2;
			x--;
			y--;
		}
		if(x>0)
		{
			if(2*c<a) ans+=x*2*c;
			else ans+=x*a;
		}
		if(y>0)
		{
			if(2*c<b) ans+=y*2*c;
			else ans+=y*b;
		}
	}
	else
	{
		ans=a*x+b*y;
	}
	printf("%d",ans);
	return 0;
}