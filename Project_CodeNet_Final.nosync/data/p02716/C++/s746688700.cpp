#include <bits/stdc++.h>
#include <variant>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin>>n;
  vecll v(n+2);
  REP(i,n)cin>>v[i];
  constexpr ll INF = 1e15;
  int offset = 2;
  vector<vecll> dp(3, vecll(n+3*offset, -INF));
  dp[0][0] = 0;
  REP(i,n+2) {
    REP(j,3) {
      dp[j][i+offset] = max(dp[j][i+offset], dp[j][i] + v[i]);
      if (j < 2) dp[j+1][i+offset+1] = max(dp[j+1][i+offset+1], dp[j][i] + v[i+1]);
      if (j < 1) dp[j+2][i+offset+2] = max(dp[j+2][i+offset+2], dp[j][i] + v[i+2]);
    }
  }
  ll ans = -INF;
  REP(i,3) ans = max(ans, dp[i][n+1+offset]);
  cout << ans << endl;
  return 0;
}
