#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

int main()
{
  string s;
  cin>>s;
  ll d;
  cin>>d;
  vector<vecll> dp(2, vecll(d, 0));
  dp[1][0] = 1;
  constexpr ll MOD = 1000000007;
  for(char c:s) {
    int num = c - '0';
    vector<vecll> tmp(2, vecll(d, 0));
    for(auto&& i:irange(0,10)) {
      for(auto&& j:irange(0l,d)) {
        tmp[0][(j+i)%d] += dp[0][j];
        tmp[0][(j+i)%d] %= MOD;
        if (i < num) {
          tmp[0][(j+i)%d] += dp[1][j];
          tmp[0][(j+i)%d] %= MOD;
        }
        if (i == num) {
          tmp[1][(j+i)%d] += dp[1][j];
          tmp[1][(j+i)%d] %= MOD;
        }
      }
    }
    swap(tmp, dp);
  }
  cout<<(dp[0][0] + dp[1][0] + MOD - 1) % MOD<<endl;
  return 0;
}
