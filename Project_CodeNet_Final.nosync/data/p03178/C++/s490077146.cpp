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
  int N, D, digits[10010];
  ll dp[10010][110];

  void init() {
    cin >> K >> D;
    N = K.size();
    rep(i, N) {
      digits[i] = K[N-i-1] - '0';
    }
  }

  void solve() {
    dp[0][0] = 1;
    REPC(j, 0, 9) dp[1][j%D]++;
    REPC(j, 0, 99) dp[2][((j%10)+(j/10))%D]++;
    REPC(i, 3, N) rep(j, D) rep(k, 10) {
      int l = j+D-k;
      while(l<0) l += D;
      dp[i][j] += dp[i-1][l%D];
      dp[i][j] %= MOD_1_000_000_007;
    }
    int acc = 0;
    ll ans = dp[N][0];
    REPCM(i, N-1, 0) {
      REPC(j, digits[i]+1, 9) {
        int k = D-acc-j;
        while(k<0) k += D;
        ans = (ans + MOD_1_000_000_007 - dp[i][k]) % MOD_1_000_000_007;
      }
      acc += digits[i];
      acc %= D;
    }
    ans = (ans + MOD_1_000_000_007 - 1) % MOD_1_000_000_007;
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
