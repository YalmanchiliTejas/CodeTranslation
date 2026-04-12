#include <iostream>
#include <vector>
#include <algorithm>
#define vll vector<ll>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
using namespace std;

int main() {
  ll n, INF = 2000000000000000000, ans = -INF;std::cin >> n;
  vll a(n);re(i, n) std::cin >> a[i];
  vvl dp = VV(n/2+1, 3, -INF, ll);
  for(int i=1;i<=n/2;i++){
    for(int j=0;j<3;j++){
      if((i-1)*2+j>=n) continue;
      ll num = a[(i-1)*2 + j];
      for(int k=0;k<=j;k++) dp[i][j] = max({dp[i][j], dp[i-1][k] + num, (i==1?num:-INF)});
    }
  }
  for(int i=0;i<3;i++) ans = max(ans, dp[n/2][i]);
  std::cout << ans << '\n';
  return 0;
}
