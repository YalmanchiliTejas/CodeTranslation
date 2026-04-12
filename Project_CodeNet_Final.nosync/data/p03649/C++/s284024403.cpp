#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) { cin >> a[i]; }
  ll ans = 0;
  while (true) {
    bool ok = true;
    REP(i, n) {
      if (a[i] >= n) {
        ok = false;
      }
    }
    if (ok) {
      break;
    }
    ll s = 0;
    REP(i, n) { s += a[i] / n; }
    REP(i, n) {
      ll k = a[i] / n;
      a[i] += s - k - k * n;
    }
    ans += s;
  }
  cout << ans << endl;
}