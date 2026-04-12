#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int n,m,ans,vis[N];
vector<int>e[N];
void dfs(int u,int s){
	if(s==n){
		ans++;return;
	} 
	vis[u]=1;
	for(int v:e[u]){
		if(!vis[v]) dfs(v,s+1);
	}
	vis[u]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v),e[u].pb(v),e[v].pb(u);
	} 
	dfs(1,1);
	printf("%d",ans);
	return 0;
}