#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define I1000000007 (1000000007)
#define I998244353   (998244353)
#define IINF             (1<<28)
#define LINF           (1LL<<60)
#define ALL(a)         (a).begin(), (a).end()
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

  string N;
  int K;
  ll DP[110][5][2];

  void init() {
    cin >> N >> K;
  }

  ll rec(int d, int k, bool smaller) {
    if(DP[d][k][smaller] >= 0) return DP[d][k][smaller];
    if(d >= N.size()) {
      if(k==0) return DP[d][k][smaller] = 1;
      else return DP[d][k][smaller] = 0;
    }
    ll res = 0;
    if(smaller) {
      if(k > 0) REPC(i, 1, 9) res += rec(d+1, k-1, smaller);
      res += rec(d+1, k, smaller);
    } else if(N[d]-'0' == 0) {
      res += rec(d+1, k, smaller);
    } else {
      if(k > 0) {
        REP(i, 1, N[d]-'0') res += rec(d+1, k-1, true);
        res += rec(d+1, k-1, false);
      }
      res += rec(d+1, k, true);
    }
    return DP[d][k][smaller] = res;
  }

  void solve() {
    memset(DP, -1, sizeof DP);
    cout << rec(0, K, false) << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}