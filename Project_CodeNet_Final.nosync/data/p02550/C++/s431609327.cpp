#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  ll n, x, m, logn, ans = 0;
  cin >> n >> x >> m;
  logn = ceil(log2(n)) + 1;
  vector<vector<ll>> nex(logn, vector<ll>(m)), sum(logn, vector<ll>(m));

  rep(i, m) {
    nex[0][i] = i * i % m;
    sum[0][i] = i;
  }

  rep(i, logn - 1) rep(j, m) {
    nex[i + 1][j] = nex[i][nex[i][j]];
    sum[i + 1][j] = sum[i][nex[i][j]] + sum[i][j];
  }

  rep(i, logn) if (n & (1ll << i)) ans += sum[i][x], x = nex[i][x];
  cout << ans << endl;
  return 0;
}