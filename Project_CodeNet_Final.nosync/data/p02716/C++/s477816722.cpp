#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  ll INF = 2000000000000000000;
  vll a(n);re(i, n) std::cin >> a[i];
  vvl dp = VV(n/2+1, 5, -INF, ll);

  for(int i=1;i<=n/2;i++){
    for(int j=0;j<5;j++){
      if((i-1)*2+j>=n) continue;
      ll num = a[(i-1)*2 + j];
      if(i==1){
        dp[1][j] = num;
      }else{
        for(int k=0;k<=j;k++) {
          dp[i][j] = max(dp[i][j], dp[i-1][k] + num);
        }
      }
    }
  }
  ll ans = -INF;
  for(int i=0;i<5;i++) ans = max(ans, dp[n/2][i]);
  std::cout << ans << '\n';
  return 0;
}
