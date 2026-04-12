#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<ll> a(1), p(1);

ll f(ll n, ll x) {
  // if (x >= 0 || x > a[N]) return 0;
  if (n == 0) {
    return (x <= 0 ? 0 : 1);
  } else if (x <= 1 + a[n - 1]) {
    return f(n - 1, x - 1);
  } else {
    return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
  }
}

int main() {
  ll n, x;
  cin >> n >> x;

  a[0] = 1, p[0] = 1;
  rep(i, n) {
    a.push_back(a[i] * 2 + 3);
    p.push_back(p[i] * 2 + 1);
  }

  cout << f(n, x) << endl;

  return 0;
}
