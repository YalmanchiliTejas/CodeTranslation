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
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 1e18;
  for (ll i = 0; i <= 2 * max(x, y); i += 2) {
    ll s = max(x - i / 2, 0LL);
    ll t = max(y - i / 2, 0LL);
    ans = min(ans, a * s + b * t + c * i);
  }
  cout << ans << endl;
}