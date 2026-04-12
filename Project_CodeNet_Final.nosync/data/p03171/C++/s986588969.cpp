#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v;
ll dp[3000][3000][2];
ll find(ll l, ll r, ll turn) {
  if(l > r) {
    return 0;
  }
  if(l == r) {
    if(turn == 0) {
  		return dp[l][r][turn] = v[l];
    } else {
    	return dp[l][r][turn] = -v[l];
    }
  }
  if(dp[l][r][turn] != 2e18) {
    return dp[l][r][turn];
  }
  if(turn == 0) {
  	dp[l][r][turn] = max(find(l + 1, r, turn ^ 1) + v[l], find(l, r - 1, turn ^ 1) + v[r]);
  } else {
  	dp[l][r][turn] = min(find(l + 1, r, turn ^ 1) - v[l], find(l, r - 1, turn ^ 1) - v[r]);
  }
  return dp[l][r][turn];
}
int main(void) {
  ll n, i, j;
  cin>>n;
  v.resize(n);
  for(ll& i: v) {
  	cin>>i;
  }
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      dp[i][j][0] = dp[i][j][1] = 2e18;
    }
  }
  ll ans = find(0, n - 1, 0);
  cout<<ans<<"\n";
}