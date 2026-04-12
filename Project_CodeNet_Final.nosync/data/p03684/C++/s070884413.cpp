#include<bits/stdc++.h>
using namespace std;
struct gg{
	int a,b,id;
}node[100010],nw[100010];
struct hh{
	int u,v,w;
}mp[200010];
int n,num,fa[100010];
int find(int x)
{return fa[x]==x?x:fa[x]=find(fa[x]);}
bool cmp(gg mo,gg ha)
{return mo.a<ha.a;}
bool cmpp(gg mo,gg ha)
{return mo.b<ha.b;}
bool cmppp(hh mo,hh ha)
{return mo.w<ha.w;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&node[i].a,&node[i].b);
		node[i].id=i;nw[i]=node[i];
	}
	sort(nw+1,nw+n+1,cmp);
	sort(node+1,node+n+1,cmpp);
	for(int i=2;i<=n;i++)
	{
		mp[++num].u=nw[i-1].id;
		mp[num].v=nw[i].id;
		mp[num].w=nw[i].a-nw[i-1].a;
		mp[++num].u=node[i-1].id;
		mp[num].v=node[i].id;
		mp[num].w=node[i].b-node[i-1].b;
	}
	int ans=0,cnt=n-1;
	sort(mp+1,mp+num+1,cmppp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=num&&cnt>=1;i++)
	{
		if(find(mp[i].u)==find(mp[i].v))continue;
		else ans+=mp[i].w,fa[find(mp[i].u)]=find(mp[i].v),cnt--;
	}
	cout<<ans;
}