#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repi(i, a, b) for (int i = (a); i < int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ull << (b))
#define uniq(v) (v).erase(unique(all(v)), (v).end())

using namespace std;
using i32 = int;
using i64 = long long;
using f64 = double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf64 = vector<f64>;
using vstr = vector<string>;

template<typename T, typename S> void amax(T &x, S y) { if (x < y) x = y; }
template<typename T, typename S> void amin(T &x, S y) { if (y < x) x = y; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
  i64 n, k;
  cin >> n >> k;
  i64 ans = n * n;
  if (k == 0) {
    cout << ans << endl;
    return 0;
  }
  ans -= n * k;
  ans -= (k - 1) * (n - k);
  repi(b, k + 1, n + 1) {
    i64 c = (n - k + 1) / b;
    ans -= c * k + max(0ll, n - b * (c + 1) + 1);
  }
  cout << ans << endl;
  return 0;
}
