#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (ll i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main() {
  ll n;
  cin >> n;
  vector<ll> s(n);
  rep(i, n) cin >> s[i];

  ll ans = 0;
  FOR(c, 1, n - 1) {
    ll res = 0;
    vector<bool> used(n, false);
    for (ll k = 0; n - 1 - k * c > 0; ++k) {
      chmax(ans, res);
      if (used[k * c]) break;
      used[k * c] = true;
      if (used[n - 1 - k * c]) break;
      used[n - 1 - k * c] = true;
      res += s[k * c] + s[n - 1 - k * c];
    }
  }
  cout << ans << endl;


  
  return 0;
}