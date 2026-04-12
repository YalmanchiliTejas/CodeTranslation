#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

const int MOD = 1000000007;

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  vector<int> imos(n+1, 0);
  for(int i = 0; i < n; i++){
    imos[i+1] = imos[i] + a[i];
    imos[i+1] %= MOD;
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    ans = (ans + a[i] * (imos[n] - imos[i+1] + MOD) % MOD )% MOD;
  }
  cout << ans << endl;

  return 0;
}