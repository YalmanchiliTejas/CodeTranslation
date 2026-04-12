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
  int n;
  cin>>n;
  vecll a(n);
  for(auto&& e:a)cin>>e;
  vector<vecll> dp(n+1, vecll(n+1));
  for(auto&& l1:irange(0,n)) {
    int l = l1+1;
    for(auto&& i:irange(0,n)) {
      if (i+l > n) break;
      dp[l][i] = max(-dp[l-1][i] + a[i+l-1], -dp[l-1][i+1] + a[i]);
    }
  }
  cout<<dp[n][0]<<endl;
  return 0;
}
