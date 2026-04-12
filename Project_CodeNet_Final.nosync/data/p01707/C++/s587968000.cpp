#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define DEBUG(x) cerr << #x << " = " << x << endl
const int MOD = 1000000007;
int N, D, X;
int psum[2001][2001];
int tmp[2001][2001];
int extgcd(int a, int b, int &x, int &y) {
  int d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}
int mod_inv(int a, int m) {
  int x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}
int combination(int n, int k) {
  if(n < k) return 0;
  int ans = 1;
  for(int i = 0; i < k; ++i) {
    ans *= (n - i) % MOD;
    ans %= MOD;
    ans *= mod_inv(k - i, MOD);
    ans %= MOD;
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  while(true) {
    cin >> N >> D >> X;
    if(N == 0 && D == 0 && X == 0) break;
    memset(tmp, 0, sizeof(tmp));
    for(int i = 1; i < X; ++i) {
      tmp[1][i] = 1;
    }
    for(int i = 1; i < 2001; ++i) {
      psum[1][i] = psum[1][i - 1] + tmp[1][i];
      psum[1][i] %= MOD;
    }
    for(int d = 2; d < 2001; ++d) {
      for(int i = 1; i < 2001; ++i) {
        int add = psum[d - 1][max<int>(0, i - 1)];
        int sub = psum[d - 1][max<int>(0, i - X)];
        tmp[d][i] = add - sub;
        tmp[d][i] = (MOD + tmp[d][i] % MOD) % MOD;
      }
      for(int i = 1; i < 2001; ++i) {
        psum[d][i] = psum[d][i - 1] + tmp[d][i];
        psum[d][i] %= MOD;
      }
    }
    //for(int d = 1; d <= 5; ++d) {
    //  cerr << "d = " << d << ":";
    //  for(int n = 0; n <= 10; ++n) {
    //    cerr << " " << tmp[d][n];
    //  }
    //  cerr << endl;
    //}
    int ans = 0;
    for(int d = 1; d <= N; ++d) {
      ans += combination(D, d) * tmp[d][N];
      // cerr << "comb " << D << " " << d << " = " << combination(D, d) << endl;
      // cerr << "tmp[" << d << "][" << N << "] = " << tmp[d][N] << endl;
      ans = (MOD + ans % MOD) % MOD;
    }
    cout << ans << endl;
  }
}