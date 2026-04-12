#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;
typedef long long LL;
const int maxn = 100005;

int ehead[maxn],ecnt;
struct edge {
	int u,v,next;
}edg[maxn*2];
void add(int u,int v) {
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,ehead[v]};
	ehead[v]=ecnt;
}

int nop[maxn],n;bool ok=false;
void dfs(int u,int fa) {
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa) {
		dfs(v,u);nop[u]+=nop[v];
	}
	ok|=nop[u]>1;nop[u]^=1;
}
int main()
{
	#ifdef Amberframe
		freopen("agc014d.in","r",stdin);
		freopen("agc014d.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int u,v,i=1;i<n;i++)
		scanf("%d %d",&u,&v),add(u,v);
	dfs(1,0);printf("%s",ok|nop[1]?"First":"Second");
	return 0;
}