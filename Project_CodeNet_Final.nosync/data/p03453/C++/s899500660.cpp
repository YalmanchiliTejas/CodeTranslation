#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const LL mod=1e9+7,inf=1LL<<60;
struct Node{
	LL x,y,c,next;
}a[400010];LL len=0,last[100010];
LL n,m,st,ed,f[2][100010];
struct node{
	LL x,d;
	node() {}
	node(LL a,LL b) {x=a;d=b;}
};
bool operator < (node a,node b) {return a.d>b.d;}
priority_queue<node> q;
void ins(LL x,LL y,LL c)
{
	a[++len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}
bool vis[100010];
LL dis[2][100010];
void dij(LL op,LL st)
{
	for(LL i=1;i<=n;i++) dis[op][i]=inf;
	memset(vis,false,sizeof(vis));
	dis[op][st]=0;q.push(node(st,0));
	while(!q.empty())
	{
		LL x=q.top().x;q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(LL i=last[x];i;i=a[i].next)
		{
			LL y=a[i].y;
			if(dis[op][y]>dis[op][x]+a[i].c)
			{
				dis[op][y]=dis[op][x]+a[i].c;
				q.push(node(y,dis[op][y]));
			}
		}
	}
}
void solve(LL op,LL st)
{
	memset(vis,false,sizeof(vis));
	f[op][st]=1;
	q.push(node(st,dis[op][st]));
	while(!q.empty())
	{
		LL x=q.top().x;q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(LL i=last[x];i;i=a[i].next)
		{
			LL y=a[i].y;
			if(dis[op][x]+a[i].c==dis[op][y])
			{
				(f[op][y]+=f[op][x])%=mod;
				q.push(node(y,dis[op][y]));
			}
		}
	}
}
LL get(LL x,LL y) {return f[0][x]*f[0][x]%mod*f[1][y]%mod*f[1][y]%mod;}
int main()
{
	scanf("%lld %lld %lld %lld",&n,&m,&st,&ed);
	for(LL i=1;i<=m;i++)
	{
		LL x,y,c;scanf("%lld %lld %lld",&x,&y,&c);
		ins(x,y,c);ins(y,x,c);
	}
	dij(0,st);dij(1,ed);
	solve(0,st);solve(1,ed);
	LL ans=f[0][ed]*f[1][st]%mod;
	/*printf("0:");for(int i=1;i<=n;i++) printf("%lld ",dis[0][i]);printf("\n");
	printf("1:");for(int i=1;i<=n;i++) printf("%lld ",dis[1][i]);printf("\n");
	printf("0:");for(int i=1;i<=n;i++) printf("%lld ",f[0][i]);printf("\n");
	printf("1:");for(int i=1;i<=n;i++) printf("%lld ",f[1][i]);printf("\n");
	printf("%lld\n",ans);*/
	for(int i=1;i<=n;i++) if(dis[0][i]==dis[1][i]&&dis[0][i]+dis[1][i]==dis[0][ed]) (ans-=get(i,i))%=mod;
	//printf("%lld\n",ans);
	for(LL i=1;i<=len;i+=2)
	{
		LL x=a[i].x,y=a[i].y;
		if(dis[0][x]>dis[0][y]) swap(x,y);
		if(dis[0][x]+dis[1][y]+a[i].c==dis[0][ed])
		{
			//printf("x y %lld %lld %lld %lld %lld\n",x,y,dis[0][x],dis[1][y],a[i].c);
			if(abs(dis[0][x]-dis[1][y])<a[i].c) (ans-=get(x,y))%=mod;
		}
	}
	printf("%lld",(ans+mod)%mod);
}