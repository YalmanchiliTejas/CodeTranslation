#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  sort(ALL(a));

  ll ans = 0;
  REP(i, n) {
    if (i < n / 2) {
      ans -= 2 * a[i];
    } else {
      ans += 2 * a[i];
    }
  }

  if (n % 2 == 0) {
    ans += a[n / 2 - 1];
    ans -= a[n / 2];
  } else {
    ll tmp1 = ans, tmp2 = ans;

    tmp1 += a[n / 2 - 1];
    tmp1 -= 3 * a[n / 2];

    tmp2 -= a[n / 2];
    tmp2 -= a[n / 2 + 1];

    ans = max(tmp1, tmp2);
  }

  cout << ans << endl;
  return 0;
}