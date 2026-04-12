#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX_N = 50;

int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> p(MX_N + 1), b(MX_N + 1);
  p[0] = 1;
  b[0] = 0;

  for (int i = 1; i <= MX_N; ++i) {
    p[i] = p[i - 1] * 2 + 1;
    b[i] = b[i - 1] * 2 + 2;
  }

  auto f = [&](ll n, ll x, ll a, auto f) {
    if (n < 0)
      return a;
    ll half = (p[n] + b[n] + 1) / 2;
    if (x < half)
      return f(n - 1, x - 1, a, f);
    else
      return f(n - 1, x - half, a + p[n] / 2 + 1, f);
  };
  ll ans = f(n, x, 0, f);

  cout << ans << endl;
}