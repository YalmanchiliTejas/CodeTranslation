
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1e18;

ll dp[3005][3005];
vector<ll> a(3005);


ll dfs(ll l, ll r){
  if (dp[l][r]!=-1)return dp[l][r];
  ll now=-INF;
  now=max(now,a[l]-dfs(l+1,r));
  now=max(now,a[r]-dfs(l,r-1));
  dp[l][r]=now;
//  cout<<now<<"l"<<l<<"r"<<r<<endl;
  return dp[l][r];

}
int main(){
  ll n;
  cin>>n;
  rep(i,n)cin>>a[i];
  rep(i,3005)rep(j,3005)dp[i][j]=-1;
  rep(i,3005)dp[i][i]=a[i];
  dfs(0,n-1);

cout<<dp[0][n-1];




}
