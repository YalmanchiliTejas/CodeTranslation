#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using ll = long long;
const ll mod = 1e9 + 7;
ll pw(ll a, ll b) {
  if (b == 0) {
    return 1LL;
  }
  if (b % 2 == 1) {
    return a * pw(a, b - 1) % mod;
  }
  ll c = pw(a, b / 2);
  return c * c % mod;
}
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll s1 = 0, s2 = 0;
  REP(i, n) {
    cin >> a[i];
    s1 = (s1 + a[i]) % mod;
    s2 = (s2 + a[i] * a[i] % mod) % mod;
  }
  ll ans = (s1 * s1 - s2 + mod) % mod;
  ans = ans * pw(2, mod - 2) % mod;
  cout << ans << endl;
  return 0;
}
