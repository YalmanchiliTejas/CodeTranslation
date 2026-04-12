#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll sum = 0;
  rep(i, n) sum = (sum + a[i]) % MOD;

  ll ans = 0;
  rep(i, n) {
    ans = (ans + (sum - a[i]) * a[i] % MOD) % MOD;
  }
  if (ans < 0) ans += MOD;
  if (ans % 2 == 0) ans /= 2;
  else ans = (ans + MOD) / 2;
  cout << ans << endl;
  return 0;
}