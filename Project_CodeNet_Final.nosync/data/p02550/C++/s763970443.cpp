#include <bits/stdc++.h>

// #include <atcoder/all>

// #LIB#

using namespace std;
// using namespace atcoder;
using ll = long long;
#define double long double
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#ifdef ONLINE_JUDGE
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');
#endif

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> pm(m), loopsum(m + 1), loopirev(m + 1);
  rep(i, m) pm[i] = (i * i) % m;
  vector<bool> seen(m);
  ll cur = x, i = 0;
  while (!seen[cur]) {
    seen[cur] = true;
    loopirev[cur] = i;
    loopsum[i + 1] = loopsum[i] + cur;
    ++i;
    cur = pm[cur];
  }
  ll loopbeginindex = loopirev[cur];
  ll loopendindex = i;
  ll loop1s = loopsum[loopendindex] - loopsum[loopbeginindex];
  ll ans = 0;
  if (n < loopbeginindex) {
    ans = loopsum[n];
  } else {
    ll nn = n - loopbeginindex;
    ll li = loopendindex - loopbeginindex;
    ans = loop1s * (nn / li) + loopsum[loopbeginindex + (nn % li)];
  }
  cout << ans << endl;
}
