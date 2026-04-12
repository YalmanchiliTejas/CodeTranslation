#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll mod = 1000000007;

ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

int main() {
  int N;
  cin >> N;
  ll x, y, a;
  x = 0;
  y = 0;
  rep(i, N) {
    cin >> a;
    x += a;
    x %= mod;
    y += a * a;
    y %= mod;
  }
  x *= x;
  x %= mod;
  ll ans = x - y;
  if (ans < 0) ans += mod;
  ans = ans * modinv(2, mod) % mod;
  cout << ans << endl;
}
