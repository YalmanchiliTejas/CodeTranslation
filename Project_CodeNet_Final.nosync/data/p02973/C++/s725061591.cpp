#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  reverse(a.begin(),a.end());

  vector<int> dp(n,1 << 30); //長さをiとしたときの末尾の最小値
  for(int i = 0; i < n; i++){
    int j = lower_bound(dp.begin(),dp.end(),a[i]+1) - dp.begin();
    dp[j] = a[i];
  }
  cout << lower_bound(dp.begin(),dp.end(),1 << 30) - dp.begin() << endl;

  return 0;
}
