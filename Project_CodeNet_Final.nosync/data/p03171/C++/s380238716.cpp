#include<cstdio>
#define ll long long 
#include<algorithm> 
ll dp[3050][3050];
int v[3050],n;
bool vis[3050][3050];
ll dfs(int l,int r){
	if (l>r)return 0;
	if (vis[l][r])return dp[l][r];
	vis[l][r]=1;
	return dp[l][r]=std::max(v[r]-dfs(l,r-1),v[l]-dfs(l+1,r));
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&v[i]);
	printf("%lld",dfs(1,n));
}