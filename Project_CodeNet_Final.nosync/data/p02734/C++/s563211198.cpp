#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <complex>
#include <vector>
#include<limits>
#include<iomanip>

using namespace std;

#define debug(x) cout << #x << ": " << x << endl;
#define ll long long
// #define mod 1000000007
#define mod 998244353
// #define COMMENT

/*   nCr % mod

const int N = 2000099;
ll fact[N];
ll finv[N];
ll inv[N];

void inverse_modulao() {
  fact[0] = fact[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;

  for(int i = 2;i < N;i++) {
    fact[i] = fact[i-1]*i%mod;
    inv[i] = mod-mod/i*inv[mod%i]%mod;
    finv[i] = finv[i-1]*inv[i]%mod;
  }
}

ll nCr(int n, int r) {
  return fact[n]*finv[r]%mod*finv[n-r]%mod;
}

*/

int N, S, A[3090], dp[3090];

int main() {

//  freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);

  cin >> N >> S;
  for(int i = 0;i < N;i++) {
    cin >> A[i];
  }

  ll ans = 0;
  for(int i = 0;i < N;i++) {
    dp[0] += 1;
    for(int j = S;j >= 0;j--) {
      if(j+A[i] <= S) {
        (dp[j+A[i]] += dp[j]) %= mod;
      }
    }

    (ans += dp[S]) %= mod;
  }
  cout << ans << endl;

  return 0;
}
