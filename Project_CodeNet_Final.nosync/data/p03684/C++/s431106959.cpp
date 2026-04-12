#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
const int N = 1e5+1;
int n,fa[N];
struct nd{LL x,y;LL id;}a[N];

struct nd2{LL w;LL x,y;} edg[N*2];

bool cmp(nd a,nd b)
{
	return a.x<b.x;
}

bool cmp2(nd a,nd b)
{
	return a.y<b.y;

}

LL find(LL x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

bool operator <(nd2 a,nd2 b)
{
	return a.w>b.w;
}

priority_queue<nd2>q[2];

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)	
		fa[i]=i;
	for(int i=1;i<=n;++i)
		cin>>a[i].x>>a[i].y;
	for(int i=1;i<=n;++i)
		a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-1;++i)
	{
		nd2 in;
		in.w=abs(a[i].x-a[i+1].x);
		in.x=a[i].id,in.y=a[i+1].id;
		q[0].push(in);
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n-1;++i)
	{
		nd2 in;
		in.w=abs(a[i].y-a[i+1].y);
		in.x=a[i].id,in.y=a[i+1].id;
		q[1].push(in);
	}
	LL ans=0;
	for(int i=1;i<=n-1;++i)
	{
		nd2 t=q[0].top();
		while(find(t.x)==find(t.y)&&!q[0].empty())
			q[0].pop(),t=q[0].top();
		nd2 t1=q[1].top();
		while(find(t1.x)==find(t1.y)&&!q[1].empty())
			q[1].pop(),t1=q[1].top();
		if(t.w<=t1.w)
		{
			ans+=t.w;
			fa[find(t.x)]=find(t.y);
		}
		else
		{
			ans+=t1.w;
			fa[find(t1.x)]=find(t1.y);
		}
	}
	cout<<ans;
}