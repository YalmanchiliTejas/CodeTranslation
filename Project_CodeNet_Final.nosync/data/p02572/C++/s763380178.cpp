#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

const int mod = 1000000007;

int main() {
  ll n, ans = 0;
  cin >> n;
  vector<ll> a(n), b(n + 1);
  rep(i, n) {
    cin >> a[i];
    b[i + 1] = (b[i] + a[i]) % mod;
  }

  for (int i = 1; i < n; i++) {
    ans += (b[i] * a[i]) % mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
