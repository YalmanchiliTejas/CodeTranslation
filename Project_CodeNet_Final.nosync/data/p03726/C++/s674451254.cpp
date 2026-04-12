#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,tot,e[500001],nt[500001],hd[500001],g[500001];
void build(int x,int y){
	tot++;
	e[tot]=y;
	nt[tot]=hd[x];hd[x]=tot;
}
void dfs(int x,int fa){
	int i;
	for(i=hd[x];i;i=nt[i]){
		if(e[i]==fa)continue;
		dfs(e[i],x);
	}
	if(!g[x]){
		if(g[fa]){
			puts("First");
			exit(0);
		}
		g[x]=g[fa]=1;
	}
}
int main(){
	int i,x,y;
	g[0]=1;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		build(x,y);build(y,x);
	}
	dfs(1,0);
	puts("Second");
}