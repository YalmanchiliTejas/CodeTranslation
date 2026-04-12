#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  auto sum = accumulate(begin(a), end(a), 0LL) % MOD;
  auto ans = sum * sum;
  for(auto &x : a) ans -= 1LL * x * x % MOD;
  ans %= MOD;
  if(ans < 0) ans += MOD;
  if(ans & 1) ans += MOD;
  cout << ans / 2 << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
