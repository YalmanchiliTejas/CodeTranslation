#include<bits/stdc++.h>
using namespace std;
#define next Next
#define int long long
const int mod=1e9+7;
const int N=4e5+5;
int n,m,S,T,sum,top,ans,x[N],y[N],z[N],dis[5][N],vis[N],gs[5][N],head[N];
struct E{
	int too,next,zh;
}edge[N*2];
struct node{
	int id,val;
};
bool operator < (node a,node b)
{
	return a.val>b.val;
}
void add(int a,int b,int c)
{
	edge[++top].too=b;edge[top].zh=c;
	edge[top].next=head[a];head[a]=top;
}
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
#define gc getchar
inline int read()
{
	int ret=0,f=0;char c=gc();
	while(!isdigit(c)){if(c=='-')f=1;c=gc();}
	while(isdigit(c)){ret=ret*10+c-48;c=gc();}
	if(f)return -ret;return ret;
}
void dj(int s,int op)
{
	memset(dis[op],0x3f,sizeof(dis[op]));
	priority_queue<node>q;
	q.push((node){s,0});
	dis[op][s]=0;gs[op][s]=1;
	memset(vis,0,sizeof(vis));
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].too,w=edge[i].zh;
			if(dis[op][v]>dis[op][u]+w)
			{
				dis[op][v]=dis[op][u]+w;
				gs[op][v]=0;
				q.push((node){v,dis[op][v]});
			}
			if(dis[op][v]==dis[op][u]+w)
			{
				gs[op][v]=(gs[op][v]+gs[op][u])%mod;
			}
		}
	}
}
signed main()
{
	n=read();m=read();
	S=read();T=read();
	for(int i=1;i<=m;i++)
	{
		x[i]=read(),y[i]=read(),z[i]=read();
		add(x[i],y[i],z[i]);
		add(y[i],x[i],z[i]);
	}
	dj(S,1);
	dj(T,2);
	if(dis[1][T]==0x3f3f3f3f3f3f3f3f){puts("0");return 0;}
	sum=dis[1][T];
	ans=gs[1][T]*gs[2][S]%mod;
//	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		if(dis[1][i]*2==sum&&dis[2][i]*2==sum)ans=(ans-gs[1][i]*gs[1][i]%mod*gs[2][i]%mod*gs[2][i]%mod+mod)%mod;
//		if(dis[2][i]+dis[1][i]==sum)ans=(ans-gs[2][i]*gs[1][i]%mod+mod)%mod;
//		cout<<ans<<endl;
	}
//	cout<<ans<<endl;
//	if(sum%2==1){cout<<ans<<endl;return 0;}
	for(int i=1;i<=m;i++)
	{
		int xu=(dis[2][y[i]]+z[i]-dis[1][x[i]])/2;
		if(dis[1][x[i]]+dis[2][y[i]]+z[i]==sum&&xu>0&&xu<z[i])ans=(ans-gs[1][x[i]]*gs[1][x[i]]%mod*gs[2][y[i]]%mod*gs[2][y[i]]%mod+mod)%mod;
		xu=(dis[1][y[i]]+z[i]-dis[2][x[i]])/2;
		if(dis[2][x[i]]+dis[1][y[i]]+z[i]==sum&&xu>0&&xu<z[i])ans=(ans-gs[2][x[i]]*gs[2][x[i]]%mod*gs[1][y[i]]%mod*gs[1][y[i]]%mod+mod)%mod;
	}
	cout<<ans;
}
/*
给出一张n个节点,m条边的无向图，给出起点s和终点t。询问两个人分别从s和t出发，走最短路不相遇的方案数。
最短路计数好题，减去不符合条件的。
不符合条件的，我们dis[s][x]+dis[t][x]=dis[s][t]
枚举在哪个点（边）相遇 
*/