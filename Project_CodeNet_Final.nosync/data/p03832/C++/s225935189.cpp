#include <bits/stdc++.h>
using namespace std;

#define int long long

#define mod (int)1000000007
#define inf (int)1000000007

#define rep(i, n) for(int i = 0; i < (n); i++)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define trrep(i, n) for(int i = (n); i >= 0; i--)
#define For(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)
#define rfor(i, s, t) for(int i = (t) - 1; i >= (s); i--)
#define trfor(i, s, t) for(int i = (t); i >= (s); i--)

int pow(int x, int n) {
  int r = 1;
  while(n > 0) {
    if(n & 1) {
      r = r * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return r;
}

int inverse(int x) {
  return pow(x, mod - 2);
}

int dp[1111];
int dpw[1111];

int cc[1111];
int ccinv[1111];

signed main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  trep(i, n) {
    dp[i] = 0;
  }
  trep(i, n) {
    if(i == 0) {
      cc[i] = 1;
    }
    else {
      cc[i] = (cc[i - 1] * i) % mod;
    }
  }
  trep(i, n) {
    ccinv[i] = inverse(cc[i]);
  }
  dp[n] = 1;
  tfor(i, a, b) {
    trep(j, n) {
      dpw[j] = dp[j];
    }
    tfor(j, c, min(d, n / i)) {
      trep(k, n) {
        if(k - j * i >= 0) {
          dpw[k - j * i] = (dpw[k - j * i] + dp[k] * ccinv[j] % mod * pow(ccinv[i], j)) % mod;
        }
      }
    }
    trep(j, n) {
      dp[j] = dpw[j];
    }
  }
  cout << dp[0] * cc[n] % mod << endl;
}
