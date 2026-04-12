#include <bits/stdc++.h>
#define ll long long
#define pb(x) push_back((x))
#define line() cerr << "DEBUG @" << __LINE__ << endl;
#define debug(x) \
  cerr << "DEBUG @" << __LINE__ << " -> " << #x << " = " << x << endl;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> v(n);
  for (ll &x : v) cin >> x;
  vector<int> pre(n + 1);
  const ll mod = 1e9 + 7;
  for (int i = 1; i <= n; i++) pre[i] = (pre[i - 1] + v[i - 1]) % mod;
  auto get = [&](int l, int r) {
    return (pre[r] - pre[l] + mod) % mod;
  };
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + (v[i] * get(i + 1, n) % mod)) % mod;
  }
  cout << ans << endl;
}
