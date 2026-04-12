#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll n, x, m;
  cin >> n >> x >> m;

  vector<int> id(m, -1);
  vector<ll> s;
  int len = 0;
  while (id[x] == -1) {
    id[x] = len++;
    s.push_back(x);
    x = x * x % m;
  }

  int d = len - id[x];
  ll ans = 0;
  if (n <= d) {
    rep(i, n) ans += s[i];
  } else {
    rep(i, id[x]) ans += s[i];
    n -= id[x];
    ll sum = 0;
    rep(i, d) sum += s[id[x] + i];
    ans += sum * (n / d);
    n %= d;
    rep(i, n) ans += s[id[x] + i];
  }
  cout << ans << endl;

  return 0;
}
