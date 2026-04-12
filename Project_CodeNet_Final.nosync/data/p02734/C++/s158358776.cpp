#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvv vector<vvl>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvvl(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
//typedef __int128_t lll;
using namespace std;

ll P = 998244353;
int main(int argc, char const *argv[]) {
  ll n, s;std::cin >> n >> s;
  vll a(n);re(i,n) std::cin >> a[i];
  vvl dp = vv(n+1, s+1, 0, ll);

  for(int i=1;i<=n;i++){
    dp[i-1][0]++;
    ll now = a[i-1];
    for(int j=0;j<=s;j++) dp[i][j] = dp[i-1][j];
    for(int j=now;j<=s;j++) dp[i][j] = (dp[i][j] + dp[i-1][j-now])%P;
  }
  /*
  for(int i=1;i<=n;i++){
    for(int j=0;j<=s;j++){
      std::cout << dp[i][j] << " " ;
    }
    std::cout  << '\n';
  }
  */
  ll ans = 0;
  for(int i=1;i<=n;i++) ans = (ans + dp[i][s])%P;
  std::cout << ans << '\n';
  return 0;
}
