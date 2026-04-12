#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
struct edge{
	int r,nxt;
}e[maxn<<1];
int d[maxn],head[maxn],esz,n,dp[maxn];
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
}
void dfs(int u,int f){
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f)dfs(e[t].r,u);
	int ans1=0,ans2=1;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f){
		ans1+=dp[e[t].r];
		for(int t2=head[e[t].r];t2;t2=e[t2].nxt)if(e[t2].r!=u)ans2+=dp[e[t2].r];
	}
	dp[u]=max(ans1,ans2);
}
int main(){
	scanf("%d",&n);
	for(int i=2,u,v;i<=n;++i)
		scanf("%d%d",&u,&v),addedge(u,v);
	dfs(1,0),printf(dp[1]<=n/2?"Second":"First");
}