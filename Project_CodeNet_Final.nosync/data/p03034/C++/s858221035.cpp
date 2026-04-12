#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, b, e) for (ll i = (ll)b; i < (ll)e; i++)
#define rep0(i, n) REP(i, 0ll, n)
#define rep1(i, n) REP(i, 1ll, n + 1)
const ll longinf = 1ll << 60;
const int inf = (1 << 30) - 1;

int main() {
  ll n;
  cin >> n;
  ll s[n];
  rep0(i, n) {
    cin >> s[i];
  }
  ll ans = 0;
  rep1(d, n - 1) {
    if ((n - 1) % d == 0) {
      ll p = (n - 1) / d;
      ll pos = 0;
      rep0(i, p + 1) {
        if (d * i != n - 1 - d * i && d * (i - 1) != n - 1 - d * i) {
          pos += (s[d * i] + s[n - 1 - d * i]);
          ans = max(pos, ans);
        } else {
          break;
        }
      }
    } else {
      long long sum = 0;
      int L = 0, R = n - 1;
      while (L + d < n - 1) {
        sum += s[L] + s[R];
        L += d;
        R -= d;
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
