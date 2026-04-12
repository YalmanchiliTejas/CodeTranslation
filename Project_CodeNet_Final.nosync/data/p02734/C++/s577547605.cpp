#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <complex>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 998244353;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;


ll powMod(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll t = powMod(x, n/2, mod);
  t = t * t % mod;
  if (n & 1) return t * x % mod;
  return t;
}

ll dp[3010][3010];
ll sum[3010][3010];

int main(void) {

  ll n, s, a[4000];
  cin >> n >> s;
  rep(i, n) cin >> a[i];

  dp[0][0] = 1;
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= s; y++) {
      if (y-a[x-1] == 0) {
	dp[x][y] = (ll)x;
      }
      if (y - a[x - 1] > 0) {
	dp[x][y] += sum[x-1][y-a[x-1]];
	dp[x][y] %= MOD;
	
      }
      sum[x][y] = (sum[x-1][y]+dp[x][y])%MOD;
    }
    
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (dp[i][s] * (ll)(n - i + 1)) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}
    
			       
