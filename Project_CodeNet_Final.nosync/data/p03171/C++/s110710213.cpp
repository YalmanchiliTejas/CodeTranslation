/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,a[3010],dp[3010][3010][2];

LL dfs(int lb,int ub,int t)
{
  if(ub<lb) return 0;
  if(dp[lb][ub][t]!=1e18) return dp[lb][ub][t];
  if(t==0) return dp[lb][ub][t]=max(dfs(lb+1,ub,1)+a[lb],dfs(lb,ub-1,1)+a[ub]);
  return dp[lb][ub][t]=min(dfs(lb+1,ub,0)-a[lb],dfs(lb,ub-1,0)-a[ub]);
}

int main()
{
  cin>>n;
  rep(i,n) cin>>a[i];
  rep(i,3005) rep(j,3005) rep(k,2) dp[i][j][k]=1e18;
  cout<<dfs(0,n-1,0)<<endl;
  return 0;
}