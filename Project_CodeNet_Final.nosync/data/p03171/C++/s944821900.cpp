#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N=3005;
typedef long long ll;
ll dp[N][N],a[N];
bool vis[N][N];
int n;
ll min_(ll a,ll b){return a<b?a:b;}
ll max_(ll a,ll b){return a>b?a:b;}
ll dfs(int l,int r){
	if(l>r) return 0LL;
	if(vis[l][r]) return dp[l][r];
	vis[l][r]=1;
	int d=n-(r-l+1);
	if(d&1) dp[l][r]=min_(dfs(l+1,r)-a[l],dfs(l,r-1)-a[r]);
	else dp[l][r]=max_(dfs(l+1,r)+a[l],dfs(l,r-1)+a[r]);
	return dp[l][r];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	printf("%lld\n",dfs(1,n));
}