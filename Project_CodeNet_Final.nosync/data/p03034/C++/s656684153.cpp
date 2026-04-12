#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <set>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  ll N;
  std::cin >> N;
  std::vector<ll> s(N);
  range(i, N) std::cin >> s[i];
  vvl dp = vv(N, 0, 0, ll);
  for(int i=1;i<N;i++){
    dp[i].push_back(0);
  }
  for(int i=1;i<N;i++){
    for(int j=1;j*i<N-1;j++){
      dp[i].push_back(dp[i][j-1]+s[N-1-j*i] + s[j*i]);
    }
  }
  ll ans = 0;
  for(int i=1;i<N;i++){
    for(int j=1;j<dp[i].size();j++) {
      if((N-1 - i*j)%i==0 && i*j>=(N-1 - i*j)) continue;
      if(i >= (N-1-i*j)) continue;
      //std::cout << dp[i][j];
      ans = max(ans, dp[i][j]);
    }
    //std::cout << '\n';
  }
  std::cout << ans << '\n';
  return 0;
}
