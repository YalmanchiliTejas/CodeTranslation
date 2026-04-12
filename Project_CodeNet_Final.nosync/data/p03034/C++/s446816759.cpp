#include <bits/stdc++.h>

// #LIB#

using namespace std;
using ll = long long;
#define double long double
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

int main() {
  ll n;
  cin >> n;
  vector<ll> s(n - 1 - 0 + 1);
  rep(i, n - 1 - 0 + 1) cin >> s[i];
  vector<vector<ll>> s_stepsum_l(n), s_stepsum_r(n);
  repr(i, 1, n) {
    ll sum = 0, cur = 0;
    s_stepsum_l[i].push_back(sum);
    while (cur < n) {
      sum += s[cur];
      s_stepsum_l[i].push_back(sum);
      cur += i;
    }
    sum = 0;
    cur = n - 1;
    s_stepsum_r[i].push_back(sum);
    while (cur >= 0) {
      sum += s[cur];
      s_stepsum_r[i].push_back(sum);
      cur -= i;
    }
  }
  ll ans = 0;
  for (ll a_b = 1; a_b <= n - 2; ++a_b) {
    ll n_1_a;
    for (ll nend = 0; (n_1_a = a_b * nend) < n - 1 - a_b; ++nend) {
      ll a = n - 1 - n_1_a, b = a - a_b;
      if (2 * a <= n - 1 && a % a_b == 0) continue;
      updatemax(ans, s_stepsum_l[a_b][nend + 1] + s_stepsum_r[a_b][nend + 1]);
    }
  }
  cout << ans << endl;
}
