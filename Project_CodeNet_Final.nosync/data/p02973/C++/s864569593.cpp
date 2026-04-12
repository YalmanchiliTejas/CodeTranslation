#include<bits/stdc++.h>

#define MOD_1_000_000_007 (1000000007LL)
#define LINF (1LL<<60)
#define rep(i, n)   for (long long i = 0; i <  (long long)(n); i++)
#define rep1(i, n)  for (long long i = 1; i <  (long long)(n); i++)
#define rep2(i, n)  for (long long i = 2; i <  (long long)(n); i++)
#define rep0c(i, n) for (long long i = 0; i <= (long long)(n); i++)
#define rep1c(i, n) for (long long i = 1; i <= (long long)(n); i++)
#define rep2c(i, n) for (long long i = 2; i <= (long long)(n); i++)
#define repc0(n, i) for (long long i = (long long)(n); i >= 0; i--)
#define repc1(n, i) for (long long i = (long long)(n); i >= 1; i--)
#define repc2(n, i) for (long long i = (long long)(n); i >= 2; i--)

namespace solver {
  using namespace std;
  typedef long long ll;
  typedef pair<ll, ll> P;

  static const ll MAX = 100010LL;
  ll N, A[MAX], dp[MAX];

  void init() {
    scanf("%lld", &N);
    rep(i, N) scanf("%lld", &A[i]);
    rep(i, N+1) dp[i] = LINF;
  }

  void solve() {
    rep(i, N) *upper_bound(dp, dp+N, -A[i]) = -A[i];
    rep(i, N+1) if(dp[i] == LINF) {
      printf("%lld\n", i);
      return;
    }
  }
}

int main() {
  solver::init();
  solver::solve();
  return 0;
}