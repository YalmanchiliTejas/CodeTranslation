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

  string K;
  int N, D;
  ll dp[10010][2][110];

  void init() {
    cin >> K >> D;
    N = K.size();
  }

  ll rec(int i, int smaller, int r) {
    ll *cur = &dp[i][smaller][r];
    if(*cur >= 0) return *cur;
    if(i >= N) return *cur = (r == 0);
    int d = K[i] - '0';
    int ub = smaller ? 9 : d;
    ll acc = 0;
    repc(j, ub) {
      ll ret = rec(i+1, (smaller || (j<ub)), (r+j)%D) % MOD_1_000_000_007;
      acc = (acc + ret) % MOD_1_000_000_007;
    }
    return *cur = acc;
  }

  void solve() {
    memset(dp, -1, sizeof dp);
    ll ans = (rec(0, 0, 0) + MOD_1_000_000_007 - 1) % MOD_1_000_000_007;
    cout << ans << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}
