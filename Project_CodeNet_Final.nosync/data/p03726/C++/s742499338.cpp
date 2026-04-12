#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100010

using namespace std;

int n,cnt;
int G[N],p[N];
struct edge{
	int t,nx;
}E[N<<1];

inline void Insert(int x,int y){
	E[++cnt].t=y; E[cnt].nx=G[x]; G[x]=cnt;
	E[++cnt].t=x; E[cnt].nx=G[y]; G[y]=cnt;
}

void dfs(int x,int f){
	for(int i=G[x];i;i=E[i].nx)
		if(E[i].t!=f) dfs(E[i].t,x);
	if(p[x]) return ;
	if(p[f]) { puts("First"); exit(0); }
	p[x]=p[f]=1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		Insert(x,y);
	}
	p[0]=1;
	dfs(1,0);
	puts("Second");
	return 0;
}