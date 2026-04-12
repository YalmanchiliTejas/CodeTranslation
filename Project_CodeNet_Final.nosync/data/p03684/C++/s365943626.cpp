#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+20;
const ll mod=1e9+7;
struct node{
	ll x,y,id;
}a[N];
struct edge{
	ll u,v,w;
}e[N];
bool cmp1(node a,node b)
{
	return a.x<b.x;
}
bool cmp2(node a,node b) 
{
	return a.y<b.y;
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int fa[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			scanf("%I64d%I64d",&a[i].x,&a[i].y),fa[i]=i,a[i].id=i;
		sort(a+1,a+1+n,cmp1);
		int cnt=0;
		for(int i=2;i<=n;i++)
			e[cnt].u=a[i].id,e[cnt].v=a[i-1].id,e[cnt++].w=abs(a[i].x-a[i-1].x);	
		sort(a+1,a+1+n,cmp2);
		for(int i=2;i<=n;i++)
			e[cnt].u=a[i].id,e[cnt].v=a[i-1].id,e[cnt++].w=abs(a[i].y-a[i-1].y);
		sort(e,e+cnt,cmp);
		int num=n;
		ll ans=0;
		for(int i=0;i<cnt;i++)
		{
			int u=e[i].u,v=e[i].v;
			int fx=find(u),fy=find(v);
			if(fx!=fy)
			{
				ans+=e[i].w;
				fa[fx]=fy;
				num--;
				if(num==1)
					break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
 