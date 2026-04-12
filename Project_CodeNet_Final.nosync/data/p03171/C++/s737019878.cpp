#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define MOD_1_000_000_007 (1000000007)
#define IINF (1<<28)
#define LINF (1LL<<60)
#define rep(i, n)      REP(i, 0, (n))
#define repc(i, n)     REPC(i, 0, (n))
#define REP(i, n, m)   for (int i = (int)(n); i <  (int)(m); i++)
#define REPC(i, n, m)  for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define yesno(cond)       YESNO((cond), "Yes", "No")
#define YESNO(cond, a, b) cout << ((cond) ? (a) : (b)) << "\n"

namespace solver {
  using namespace std;
  typedef long long ll;

  static const int MAX = 3030;
  int N, as[MAX];
  ll dp[MAX][MAX];

  void init() {
    cin >> N;
    rep(i, N) {
      cin >> as[i];
    }
    repc(l, N) REPC(r, l, N) {
      if((N-r+l)%2) dp[l][r] = LINF;
      else dp[l][r] = -LINF;
    }
  }

  ll rec(int l, int r, bool turn) {
    if(abs(dp[l][r]) != LINF) return dp[l][r];
    if(l==r) return dp[l][r] = 0;
    if(turn) {
      dp[l][r] = max(dp[l][r], rec(l+1, r, !turn) + as[l]);
      dp[l][r] = max(dp[l][r], rec(l, r-1, !turn) + as[r-1]);
    } else {
      dp[l][r] = min(dp[l][r], rec(l+1, r, !turn) - as[l]);
      dp[l][r] = min(dp[l][r], rec(l, r-1, !turn) - as[r-1]);
    }
    return dp[l][r];
  }

  void solve() {
    cout << rec(0, N, true) << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}