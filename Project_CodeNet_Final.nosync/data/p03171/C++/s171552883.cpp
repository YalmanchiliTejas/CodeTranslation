#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define I_1000000007 (1000000007)
#define I_998244353   (998244353)
#define I_INF             (1<<28)
#define L_INF           (1LL<<60)
#define rep(i, n)      REP(i, 0, (n))
#define repc(i, n)     REPC(i, 0, (n))
#define REP(i, n, m)   for (int i = (int)(n); i <  (int)(m); i++)
#define REPC(i, n, m)  for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define yesno(cond)       YESNO((cond), "Yes", "No")
#define YESNO(cond, a, b) cout << ((cond) ? (a) : (b)) << "\n"
template<class T> inline bool chmin(T& a, const T& b) {
  if (a > b) { a = b; return true; } else return false;
}
template<class T> inline bool chmax(T& a, const T& b) {
  if (a < b) { a = b; return true; } else return false;
}

namespace solver {
  using namespace std;
  using ll = long long;

  int N, as[3030];
  ll dp[3030][3030][2];

  void init() {
    cin >> N;
    rep(i, N) {
      cin >> as[i];
    }
  }

  ll rec(int l, int r, bool turn) {
    if(dp[l][r][turn] > -L_INF) return dp[l][r][turn];
    int k = 1;
    if(turn) k = -1;
    if(l == r-1) return dp[l][r][turn] = k * as[l];
    ll left = rec(l+1, r, !turn) + k * as[l];
    ll right = rec(l, r-1, !turn) + k * as[r-1];
    if(turn) {
      return dp[l][r][turn] = min(left, right);
    } else {
      return dp[l][r][turn] = max(left, right);
    }
  }

  void solve() {
    repc(i, N) repc(j, N) rep(k, N) dp[i][j][k] = -L_INF;
    cout << rec(0, N, 0) << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}