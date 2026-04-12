#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include <string.h>
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int maxn=200005;
long long ans1,ans2=1e18,n,da,xiao,maxx,maxy,minx=1e9+10,miny=1e9+10,weizhiy,weizhix;
struct pai
{
	long long x,y;
	bool operator < (const pai &a)const
	{
		long long gx1,gx2;
		if(xiao<=x&&x<=da)
			gx1=0;
		else if(xiao<=y&&y<=da)
			gx1=0;
		else if(y<xiao)
			gx1=xiao-y;
		else if(x>da)
			gx1=x-da;
		else 
			gx1=min(xiao-x,y-da);
		if(xiao<=a.x&&a.x<=da)
			gx2=0;
		else if(xiao<=a.y&&a.y<=da)
			gx2=0;
		else if(a.y<xiao)
			gx2=xiao-a.y;
		else if(a.x>da)
			gx2=a.x-da;
		else 
			gx2=min(xiao-a.x,a.y-da);
		return gx1>gx2;
	}
} p[maxn];
int main()
{
//	file("1"); 
	scanf("%lld",&n);
	if(n==1)
	{
		printf("0");
		return 0;
	}
	for(int i=1; i<=n; i++)
	{
		scanf("%lld%lld",&p[i].x,&p[i].y);
		if(p[i].x>p[i].y)
			swap(p[i].x,p[i].y);
		maxx=max(maxx,p[i].x);
		if(p[i].y>maxy)
		{
			weizhiy=i;
			maxy=p[i].y;
		}
		if(p[i].x<minx)
		{
			weizhix=i;
			minx=p[i].x;
		}
		miny=min(miny,p[i].y);
	}
	ans1=(maxy-miny)*(maxx-minx);
//	cout<<ans1<<endl;
	da=p[weizhix].y,xiao=p[weizhiy].x;
	sort(p+1,p+n+1);
	if(da<xiao)
		swap(da,xiao);
	if(weizhix!=weizhiy)
	{
		for(int i=1; i<=n; i++)
		{
			int t=i;
			if((xiao<=p[i].x&&p[i].x<=da)||(xiao<=p[i].y&&p[i].y<=da))
				continue;
			else if(p[i].x>da)
				da=p[i].x;
			else if(p[i].y<xiao)
				xiao=p[i].y;
			else if(xiao-p[i].x<p[i].y-da)
				xiao=p[i].x;
			else
				da=p[i].y;
		}
		ans2=(maxy-minx)*(da-xiao);
	}
//	cout<<ans2<<endl;
	printf("%lld",min(ans1,ans2));
	return 0;
}
