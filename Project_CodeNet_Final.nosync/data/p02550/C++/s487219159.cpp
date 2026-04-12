#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

void solve() {
  long long n, x, m; scanf("%lld%lld%lld", &n, &x, &m);
  map<long long, int> mp;
  vector<long long> cum;
  cum.push_back(0);
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    if (mp.count(x)) {
      // loop found
      const long long &prev = mp[x];
      n -= i;
      ans += (cum.back()-cum[prev])*(n/(i-prev));
      ans += cum[prev+n%(i-prev)]-cum[prev];
      break;
    }
    ans += x;
    cum.push_back(ans);
    mp[x] = i;
    (x *= x) %= m;
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
