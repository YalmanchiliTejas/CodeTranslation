#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  int ans = 0;
  int x = 0;

  rep(i, n) {
    ans = (ans + (ll)a[i] * x) % MOD;
    x = (x + a[i]) % MOD;
  }

  cout << ans << endl;

  return 0;
}
