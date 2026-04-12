#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<ll> b(n + 1, 0);  // 累積和テーブル
  rep(i, 0, n) {
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }

  ll ans = 0;

  // i について全探索する
  rep(i, 0, n) {
    // 累積和を使って a[i+1] + ... + a[n] を求める
    ll tot = (b[n] - b[i + 1]) % MOD;
    ans += a[i] * tot;
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
