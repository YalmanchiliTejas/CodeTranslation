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
  string n;
  cin>>n;
  int k;
  cin>>k;
  int len = n.size();
  vector<vector<vecll>> dp(2, vector<vecll>(k+1, vecll(len+1)));
  dp[0][0][0] = 1;
  for(auto&& i:irange(0,len)) {
    int dgt = n[i] - '0';
    for(auto&& j:irange(0,k)) {
      for(auto&& a:irange(1,10)) {
        if (a < dgt) {
          dp[1][j+1][i+1] += dp[0][j][i];
        } else if (a == dgt) {
          dp[0][j+1][i+1] += dp[0][j][i];
        }
        dp[1][j+1][i+1] += dp[1][j][i];
      }
    }
    for(auto&& j:irange(0,k+1)) {
      if (dgt == 0) {
        dp[0][j][i+1] += dp[0][j][i];
      } else {
        dp[1][j][i+1] += dp[0][j][i];
      }
      dp[1][j][i+1] += dp[1][j][i];
    }
  }
  cout<<dp[0][k][len] + dp[1][k][len]<<endl;
  return 0;
}
