#include<cstdio>
#define N 3005
#define ll long long
int n,a[N];
ll dp[N][N][2];
int vis[N][N][2];
void chk(ll &x,ll y){if(y>x)x=y;}
ll DP(int l,int r,int i){
	if(l>r)return 0;
	if(vis[l][r][i])return dp[l][r][i];
	vis[l][r][i]=1;
	dp[l][r][i]=-1e18;
	chk(dp[l][r][i],a[l]-DP(l+1,r,i^1));
	chk(dp[l][r][i],a[r]-DP(l,r-1,i^1));
	return dp[l][r][i];
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	printf("%lld\n",DP(0,n-1,0));
	return 0;
}