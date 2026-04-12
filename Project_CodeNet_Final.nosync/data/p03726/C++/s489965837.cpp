#include<bits/stdc++.h>
using namespace std;

const int S=1<<20;
char buf[S],*H,*T;
inline char Get()
{
	if(H==T) T=(H=buf)+fread(buf,1,S,stdin);
	if(H==T) return -1;return *H++;
}
inline int read()
{
	int x=0;char c=Get();
	while(!isdigit(c)) c=Get();
	while(isdigit(c)) x=x*10+c-'0',c=Get();
	return x;
}

const int N=100010;
struct Edge{int to,next;} e[N<<1];
int h[N],sum=0,n;
int deg[N],g[N];

void add_edge(int u,int v)
{
	e[++sum].to=v;
	e[sum].next=h[u];
	h[u]=sum;
}

int dfs(int u,int fa)
{
	int falun=0;
	for(int tmp=h[u];tmp;tmp=e[tmp].next)
	{
		int v=e[tmp].to;
		if(v==fa) continue;
		falun+=dfs(v,u);
	}
	if(falun>=2) puts("First"),exit(0);
	return falun^1;
}

int main()
{
	int u,v;
	n=read();
	for(int i=1;i<n;i++)
	{
		u=read();v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	puts(dfs(1,0)?"First":"Second");
	return 0;
}