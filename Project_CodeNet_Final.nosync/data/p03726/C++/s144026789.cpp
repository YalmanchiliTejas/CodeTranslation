#include <cstdio>
#include <cstring>
#define MAXN 100010

struct edge{
	int to,next;
	edge(int _to=0,int _next=0):to(_to),next(_next){}
}e[MAXN<<1];

int n;
int g[MAXN],nume;
int f[MAXN],h[MAXN];

void addEdge(int u,int v){
	e[nume]=edge(v,g[u]);
	g[u]=nume++;
}

void dfs(int x,int p){
	int c0=0,cf=0,cg=0;
	for(int i=g[x];~i;i=e[i].next)
		if(e[i].to^p){
			c0++;
			dfs(e[i].to,x);
			if(f[e[i].to]) cf++;
			if(h[e[i].to]) cg++;
		}
	if(cf>=2 || cg==c0) f[x]=1;
	if(cf>=1) h[x]=1;
}

int main(){
	memset(g,-1,sizeof g);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	dfs(1,0);
	if(f[1]) puts("First");
	else puts("Second");
	return 0;
}
