#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 3010
using namespace std;
ll n,dp[N][N],a[N],qdh[N],sum=0;
ll dfs(ll l,ll r)
{
	if(l>r)
	{
		return 0;
	}
	if(dp[l][r]!=-1)
	{
		return dp[l][r];
	}
	dp[l][r]=max(dp[l][r],qdh[r+1]-qdh[l]-dfs(l+1,r));
	dp[l][r]=max(dp[l][r],qdh[r+1]-qdh[l]-dfs(l,r-1));
	return dp[l][r];
}
int main(){
	ll i,j;
	cin>>n;
	qdh[0]=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		qdh[i+1]=qdh[i]+a[i];
		sum+=a[i];
	}
	memset(dp,-1,sizeof(dp));
	i=dfs(0,n-1);
	cout<<i-(sum-i)<<endl;
	return 0;
}