#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  ll n, x, m, logn = 1, ans = 0;
  cin >> n >> x >> m;
  while ((1ll << logn) < n) logn++;
  vector<vector<ll>> nex(logn, vector<ll>(m, -1)), sum(logn, vector<ll>(m, 0));

  for (ll r = 0; r < m; ++r) {
    nex[0][r] = r * r % m;
    sum[0][r] = r;
  }

  for (int p = 0; p < logn - 1; ++p)
    for (int r = 0; r < m; ++r) {
      nex[p + 1][r] = nex[p][nex[p][r]];
      sum[p + 1][r] = sum[p][r] + sum[p][nex[p][r]];
    }

  for (int p = 0; p < logn; ++p)
    if (n & (1LL << p)) ans += sum[p][x], x = nex[p][x];

  cout << ans << endl;
  return 0;
}
