#include <bits/stdc++.h>
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

constexpr ll MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,s;
  cin>>n>>s;
  vecll a(n);
  for(auto&& e:a)cin>>e;
  ll ans = 0;
  vecll dp(s);
  dp[0] = 1;
  REP(i,n) {
    vecll tmp = dp;
    if (a[i] < s) {
      tmp[a[i]] += dp[0] * (i+1);
      tmp[a[i]] %= MOD;
    }
    FOR(j,a[i]+1,s) {
      tmp[j] += dp[j-a[i]];
      tmp[j] %= MOD;
    }
    if (s > a[i]) {
      ans += dp[s-a[i]] * (n-i);
      ans %= MOD;
    } else if (s == a[i]) {
      ans += (i+1) * (n-i);
      ans %= MOD;
    }
    swap(tmp, dp);
  }
  cout<<ans<<endl;
  return 0;
}
