#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>(b);i--)
#define pb push_back

typedef long long ll;
using namespace std;
const int MOD = 1000000007;
const int nl = 1001;

ll dp[nl][nl];
ll fac[nl], inv_fac[nl];
int N, A, B, C, D;

ll inv(int n, int m){
  int _n = n % m;
  int _m = m;
  int div, mod;
  int l[2] = {1, 0};
  int r[2] = {0, 1};
  int _[2];
  ll ret;
  bool b = true;
  while (_n > 1){
    b = ! b;
    div = _m / _n;
    mod = _m % _n;
    if ( mod < 0){
      div -= 1;
      mod += _n;
    }
    _m = _n;
    _n = mod;
    l[0] += div*r[0];
    l[1] += div*r[1];
    _[0] = r[0];
    _[1] = r[1];
    r[0] = l[0];
    r[1] = l[1];
    l[0] = _[0];
    l[1] = _[1];
  }
  ret = r[1];
  if(!b)ret *= -1;
  ret %= m;
  if(ret < 0)ret += m;
  return ret;
}
void set_fac(){
  fac[0] = 1;
  inv_fac[0] = 1;
  FOR(i, 1, nl){
    fac[i] = fac[i - 1] * i % MOD;
    inv_fac[i] = inv_fac[i - 1] * inv(i, MOD) % MOD;
  }
  return;
}
ll powMod(int a, int n, int m){
  ll pro = 1, tmp = a;
  for(; n > 0; n >>= 1){
    if(n & 1) pro = (pro * tmp) % m;
    tmp = tmp * tmp % m;
  }
  return pro;
}
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int _j;

  cin >> N >> A >> B >> C >> D;
  set_fac();
  FOR(i, 0, nl){
    FOR(j, 0, nl){
      dp[i][j] = 0;
    }
  }
  FOR(i, 0, B + 1){
    dp[i][0] = 1;
  }
  FOR(i, A, B+1){
    FOR(j, 0, N + 1){
      dp[i][j] = dp[i - 1][j];
      FOR(k, C, D + 1){
        _j = j - k * i;
        if(_j < 0)break;
        dp[i][j] += dp[i - 1][_j] * fac[j] % MOD * inv_fac[_j] % MOD * powMod(inv_fac[i], k, MOD) % MOD * inv_fac[k];
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[B][N] << endl;
  return 0;
}
