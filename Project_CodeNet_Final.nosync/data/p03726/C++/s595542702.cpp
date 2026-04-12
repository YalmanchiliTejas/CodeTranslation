#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=500005;

struct E{
	int to,next;
}mem[N<<1];
int n,num,x,y,ans;
int f[N],g[N],head[N],cnt[N],p[N];

void add(int x,int y){
	num++;
	mem[num].to=y; mem[num].next=head[x];
	head[x]=num;
}

void dfs1(int k,int pre){
	int u,j;
	g[k]=1; f[k]=0;
	for (j=head[k];j;j=mem[j].next){
		u=mem[j].to;
		if (u==pre) continue;
		dfs1(u,k);
		f[k]|=g[u]; g[k]&=f[u];
		if (g[u]) cnt[k]++,p[k]=u;
	}
}

void dfs2(int k,int pre){
	int u,j;
	if (g[k]) ans=1;
	if (ans) return;
	for (j=head[k];j;j=mem[j].next){
		u=mem[j].to;
		if (u==pre) continue;
		if (cnt[k]>1||(cnt[k]==1&&p[k]!=u)) g[u]&=1;
		else g[u]&=0;
		dfs2(u,k);
	}
}

int main(){
	int i;
	scanf("%d",&n);
	for (i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	if (ans) printf("First\n");
	else printf("Second\n");
	return 0;
}