#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL 
#include "e:/Codes/lib/prettyprint.hpp"
#else
#define debug(...) 
#endif

int32_t main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  
  int n, x, m;
  cin >> n >> x >> m;
  
  x %= m;
  int cnt = 1, ans = 0;
  map<int, int> mp;
  vector<int> vals;
  vals.push_back(0);

  while (1) {
    if (mp[x]) break;
    mp[x] = cnt++;
    vals.push_back(vals.back() + x);
    x = x * x % m;
  }

  if (n < cnt) ans += vals[n];
  else {
    int cy = cnt - mp[x];
    debug(cy, cnt, mp[x], x);
    n -= mp[x] - 1;
    ans += (n / cy) * (vals.back() - vals[mp[x]-1]);
    n %= cy;
    n += mp[x] - 1;
    ans += vals[n];
    debug(n);
  }

  cout << ans << '\n';
}
