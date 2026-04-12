
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const int N = 200000;
ll fac[N*2+10];
ll invfac[N*2+10];

ll mypow(ll x, ll n) {
  if(n == 0) return 1;
  if(n % 2 == 0) return mypow(x*x%MOD, n/2);
  return mypow(x*x%MOD, n/2) * x % MOD;
}

inline ll cmb(ll n, ll k) {
  if(k < 0 || n < k) return 0;
  return fac[n] * invfac[k] % MOD * invfac[n-k] % MOD;
}

int main(void) {
  fac[0] = 1;
  REP(i, N*2) {
    fac[i+1] = fac[i] * (i+1) % MOD;
  }
  invfac[N*2] = mypow(fac[N*2], MOD-2);
  for(int i = N*2; i > 0; --i) {
    invfac[i-1] = invfac[i] * i % MOD;
  }
  ll n, m, k;
  cin >> n >> m >> k;
  ll res = 0;
  for(ll d = 1; d <= n-1; ++d) {
    res = (res + d*m %MOD *m %MOD *(n-d)%MOD) % MOD;
  }
  for(ll d = 1; d <= m-1; ++d) {
    res = (res + d*n %MOD *n %MOD *(m-d)%MOD) % MOD;
  }
  cout << res * cmb(n*m-2, k-2) % MOD << endl;
  return 0;
}
