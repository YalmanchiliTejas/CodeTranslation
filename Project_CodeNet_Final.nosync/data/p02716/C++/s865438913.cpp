#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define each(x, y) for (auto &x : y)
#define all(a) (a).begin(), (a).end()
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))
#define sz(v) ((int) v.size())

using namespace std;

using i64 = long long;
using f80 = long double;
using vi32 = vector<int>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void yes() { cout << "Yes" << endl; exit(0); }
inline void no() { cout << "No" << endl; exit(0); }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> inline void amax(T &x, T y) { x = max(x, y); }
template <typename T> inline void amin(T &x, T y) { x = min(x, y); }
template <typename T> inline T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

i64 dp[200001][3][2];

void solve() {
  int n;
  cin >> n;
  vi32 a(n);
  cin >> a;
  repc(i, n) rep(j, 3) rep(k, 2) {
    dp[i][j][k] = -1e18;
  }
  dp[0][1][0] = 0;
  rep(i, n) rep(j, 3) rep(k, 2) rep(l, 2) {
    if (dp[i][j][k] == -1e18) continue;
    if (k == 1 && l == 1) {
      continue;
    }
    if (i & 1) {
      if (l == 0) {
        if (j == 0) continue;
        amax(dp[i + 1][j - 1][0], dp[i][j][k]);
      } else {
        amax(dp[i + 1][j][1], dp[i][j][k] + a[i]);
      }
    } else {
      if (l == 0) {
        amax(dp[i + 1][j][0], dp[i][j][k]);
      } else {
        if (j == 2) continue;
        amax(dp[i + 1][j + 1][1], dp[i][j][k] + a[i]);
      }
    }
  }
  i64 ans = -1e18;
  rep(k, 2) amax(ans, dp[n][1][k]);
  cout << ans << endl;
}