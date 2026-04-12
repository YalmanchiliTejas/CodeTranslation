#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());
  if (n % 2 == 1) {
    ll ans = 0;
    rep(i, n / 2) ans -= a[i] * 2;
    ans += a[n / 2] + a[n / 2 + 1];
    FOR(i, n / 2 + 2, n) ans += a[i] * 2;
    ll res = 0;
    rep(i, n / 2 - 1) res -= a[i] * 2;
    res -= a[n / 2 - 1] + a[n / 2];
    FOR(i, n / 2 + 1, n) res += a[i] * 2;
    chmax(ans, res);
    cout << ans << endl;
  }
  else {
    ll ans = 0;
    rep(i, n / 2 - 1) {
      ans -= a[i] * 2;
    }
    ans += a[n / 2] - a[n / 2 - 1];
    FOR(i, n / 2 + 1, n) {
      ans += a[i] * 2;
    }
    cout << ans << endl;
  }


  
  return 0;
}