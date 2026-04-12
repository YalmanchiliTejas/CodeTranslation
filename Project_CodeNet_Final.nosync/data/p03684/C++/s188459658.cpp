#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,x,y) for(int i=x;i<=y;++i)
using namespace std;
const int Maxn=1e5+5;
int n,f[Maxn],pos1,pos2,cnt;
long long ans;
struct Point
{
	int pos,id;
}x[Maxn],y[Maxn];
struct Edge
{
	int u,v,val;
}xz[Maxn],yz[Maxn];
bool cmp1(Point a,Point b)
{
	return a.pos<b.pos;
}
bool cmp2(Edge a,Edge b)
{
	return a.val<b.val;
}
int findfa(int u)
{
	return f[u]==u?u:f[u]=findfa(f[u]);
}
int main()
{
	//freopen("std.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].pos>>y[i].pos;
		x[i].id=i;y[i].id=i;
		f[i]=i;
	}
	sort(x+1,x+n+1,cmp1);
	sort(y+1,y+n+1,cmp1);
	for(int i=1;i<n;i++)
	{
		xz[i].u=x[i].id;
		xz[i].v=x[i+1].id;
		xz[i].val=x[i+1].pos-x[i].pos;
	}
	for(int i=1;i<n;i++)
	{
		yz[i].u=y[i].id;
		yz[i].v=y[i+1].id;
		yz[i].val=y[i+1].pos-y[i].pos;
	}
	sort(xz+1,xz+n+1,cmp2);
	sort(yz+1,yz+n+1,cmp2);
	pos1=pos2=1;
	while(cnt<n-1)
	{
		if(xz[pos1].val<yz[pos2].val)
		{
			if(findfa(xz[pos1].u)!=findfa(xz[pos1].v))
			{
				f[findfa(xz[pos1].v)]=findfa(xz[pos1].u);
				cnt++;
				ans+=xz[pos1].val;
			}
			pos1++;
		}
		else
		{
			if(findfa(yz[pos2].u)!=findfa(yz[pos2].v))
			{
				f[findfa(yz[pos2].v)]=findfa(yz[pos2].u);
				cnt++;
				ans+=yz[pos2].val;
			}
			pos2++;
		}
	}
	cout<<ans;
	return 0;
}
