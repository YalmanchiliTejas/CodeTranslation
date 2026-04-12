#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  static int dp[3001][3001];
  fill(dp[0],dp[3000]+3000,-(1<<30));
  function< int(int,int) > rec =
  [&](int l,int r){
    if(l > r) return 0LL;
    if(dp[l][r] != -(1<<30)) return dp[l][r];
    int res = max(a[l] - rec(l+1,r),a[r] - rec(l,r-1));
    return dp[l][r] = res;
  };
  cout << rec(0,n-1) << endl;

  return 0;
}
