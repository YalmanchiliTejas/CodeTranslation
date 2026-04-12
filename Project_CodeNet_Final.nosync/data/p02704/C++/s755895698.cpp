#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<int> s(n), t(n);
  REP(i, n) cin >> s[i];
  REP(i, n) cin >> t[i];
  using ull = unsigned long long;
  vector<ull> u(n), v(n);
  REP(i, n) cin >> u[i];
  REP(i, n) cin >> v[i];
  function<vector<vector<int>>(const vector<int>&, const vector<int>&)> solve = [&](const vector<int> &a, const vector<int> &b) {
    // REP(i, n) cout << a[i] << " \n"[i + 1 == n];
    // REP(i, n) cout << b[i] << " \n"[i + 1 == n];
    // cout << '\n';
    vector res(n, vector(n, 0));
    int zero = 0, one = 0;
    vector<int> ok, ng_zero, ng_one;
    REP(i, n) {
      REP(j, n) res[i][j] = a[i];
      if (s[i] == 0) {
        if (a[i] == 0) {
          ng_zero.emplace_back(i);
        } else {
          ++one;
        }
      } else if (s[i] == 1) {
        if (a[i] == 1) {
          ng_one.emplace_back(i);
        } else {
          ++zero;
        }
      }
    }
    function<void()> fn_zero = [&]() {
      while (!ng_zero.empty()) {
        ok.emplace_back(ng_zero.back());
        ng_zero.pop_back();
      }
    };
    function<void()> fn_one = [&]() {
      while (!ng_one.empty()) {
        ok.emplace_back(ng_one.back());
        ng_one.pop_back();
      }
    };
    REP(j, n) {
      if (t[j] == 0) {
        int bit = 1;
        REP(i, n) bit &= res[i][j];
        if (b[j] == 0) {
          if (bit == 0) {
            fn_zero();
            fn_one();
          } else if (bit == 1) {
            if (!ok.empty()) {
              res[ok.back()][j] = 0;
              fn_zero();
              fn_one();
            } else if (ng_one.empty()) {
              return vector<vector<int>>();
            } else {
              res[ng_one[0]][j] = 0;
              while (ng_one.size() >= 2) {
                ok.emplace_back(ng_one.back());
                ng_one.pop_back();
              }
            }
          }
        } else if (b[j] == 1) {
          if (bit == 0) {
            if (zero > 0) return vector<vector<int>>();
            REP(i, n) res[i][j] = 1;
            fn_one();
          } else if (bit == 1) {
            fn_zero();
            fn_one();
          }
        }
      } else if (t[j] == 1) {
        int bit = 0;
        REP(i, n) bit |= res[i][j];
        if (b[j] == 0) {
          if (bit == 0) {
            fn_zero();
            fn_one();
          } else if (bit == 1) {
            if (one > 0) return vector<vector<int>>();
            REP(i, n) res[i][j] = 0;
            fn_zero();
          }
        } else if (b[j] == 1) {
          if (bit == 0) {
            if (!ok.empty()) {
              res[ok.back()][j] = 1;
              fn_zero();
              fn_one();
            } else if (ng_zero.empty()) {
              return vector<vector<int>>();
            } else {
              res[ng_zero[0]][j] = 1;
              while (ng_zero.size() >= 2) {
                ok.emplace_back(ng_zero.back());
                ng_zero.pop_back();
              }
            }
          } else if (bit == 1) {
            fn_zero();
            fn_one();
          }
        }
      }
    }
    return ng_zero.empty() && ng_one.empty() ? res : vector<vector<int>>();
  };
  vector ans(n, vector(n, static_cast<ull>(0)));
  REP(bit, 64) {
    vector<int> a(n), b(n);
    REP(i, n) a[i] = u[i] >> bit & 1;
    REP(i, n) b[i] = v[i] >> bit & 1;
    vector<vector<int>> now = solve(a, b);
    // REP(i, n) REP(j, n) cout << now[i][j] << " \n"[j + 1 == n];
    // cout << '\n';
    if (now.empty()) {
      cout << "-1\n";
      return 0;
    }
    REP(i, n) REP(j, n) ans[i][j] |= static_cast<ull>(now[i][j]) << bit;
  }
  // REP(i, n) {
  //   ull bit = ans[i][0];
  //   if (s[i] == 0) {
  //     FOR(j, 1, n) bit &= ans[i][j];
  //   } else if (s[i] == 1) {
  //     FOR(j, 1, n) bit |= ans[i][j];
  //   }
  //   cout << bit << " \n"[i + 1 == n];
  // }
  // REP(j, n) {
  //   ull bit = ans[0][j];
  //   if (t[j] == 0) {
  //     FOR(i, 1, n) bit &= ans[i][j];
  //   } else if (t[j] == 1) {
  //     FOR(i, 1, n) bit |= ans[i][j];
  //   }
  //   cout << bit << " \n"[j + 1 == n];
  // }
  REP(i, n) REP(j, n) cout << ans[i][j] << " \n"[j + 1 == n];
  return 0;
}
