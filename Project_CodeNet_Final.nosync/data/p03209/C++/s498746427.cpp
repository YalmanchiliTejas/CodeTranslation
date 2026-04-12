#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  ll x;
  cin >> n >> x;

  vector<ll> p(51);
  vector<ll> pb(51);
  p[0] = 1;
  pb[0] = 1;
  for (int i = 1; i < 51; i++) {
    p[i] = p[i - 1] * 2 + 1;
    pb[i] = pb[i - 1] * 2 + 3;
  }

  // レベルnからx枚食べた時のパティの数
  function<ll(int, ll)> f = [&](int n, ll x) -> ll {
    if (n < 0 || x <= 0)
      return 0ll;

    if (x >= pb[n])
      return p[n];

    if (x <= pb[n] / 2) {
      return f(n - 1, x - 1);
    } else {
      return p[n - 1] + 1 + f(n - 1, x - pb[n - 1] - 2);
    }
  };

  cout << f(n, x) << endl;

  return 0;
}
