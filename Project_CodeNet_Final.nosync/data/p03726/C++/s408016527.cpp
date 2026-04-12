#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005,INF=1000000000;
int n,cnt,Cnt,h[N],H[N],dis[N],cur[N],g[N],ans,s,t;
struct edge{int v,f,n;} e[N*6],E[N<<1];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v)
{
	E[Cnt]=(edge){v,0,H[u]},H[u]=Cnt++;
	E[Cnt]=(edge){u,0,H[v]},H[v]=Cnt++;
}

void addedge(int u,int v,int f)
{
	e[cnt]=(edge){v,f,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,0,h[v]},h[v]=cnt++;
}

void dfs(int x,int fa,bool dep)
{
	if(dep) addedge(s,x,1);
	else addedge(x,t,1);
	for(int i=H[x]; i!=-1; i=E[i].n)
		if(E[i].v!=fa)
		{
			if(dep) addedge(x,E[i].v,INF);
			else addedge(E[i].v,x,INF);
			dfs(E[i].v,x,dep^1);
		}
}

int isap(int x,int rt)
{
	if(x==t) return rt;
	int sum=0;
	for(int i=cur[x]; i!=-1; i=e[i].n)
		if(e[i].f && dis[e[i].v]+1==dis[x])
		{
			int f=isap(e[i].v,min(e[i].f,rt-sum));
			e[i].f-=f,e[i^1].f+=f,sum+=f;
			if(cur[x]=i,rt==sum || dis[s]>=t) return sum;
		}
	if(!(--g[dis[x]++])) dis[s]=t;
	++g[dis[x]],cur[x]=h[x];
	return sum;
}

int main()
{
	n=getint(),s=n+1,t=s+1;
	memset(h,-1,sizeof(h));
	memset(H,-1,sizeof(H));
	if(n&1) {puts("First"); return 0;}
	rep(i,1,n-1) addedge(getint(),getint());
	dfs(1,0,1),memcpy(cur,h,sizeof(h));
	for(g[0]=t; dis[s]<t; ans+=isap(s,INF));
	if(ans==(n>>1)) puts("Second");
	else puts("First");
	return 0;
}