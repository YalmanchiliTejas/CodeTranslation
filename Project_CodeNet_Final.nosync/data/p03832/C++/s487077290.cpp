
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

ll cmb[1010][1010];


long long inv(int a, int p) { return a==1 ? 1 : (1-p*inv(p%a,a))/a+p; }

ll facmemo[1010];
ll fac(int n) {
  ll& res = facmemo[n];
  if(res == 0) {
    res = 1;
    for(int i = 1; i <= n; ++i) {
      res = (res * i) % MOD;
    }
  }
  return res;
}

ll calc(int rest, int mini, int here) {
  ll x = inv(fac(here), MOD);
  REP(i, here) {
    x = (x * cmb[rest][mini]) % MOD;
    rest -= mini;
  }
  return x;
}

int A, B, C, D;
ll memo[1010][1010];
int solve(int rest, int mini) {
  ll& res = memo[rest][mini];
  if(res < 0) {
    if(rest == 0) {
      res = 1;
    } else if(mini > B) {
      res = 0;
    } else {
      res = solve(rest, mini+1);
      for(int here = C; here <= D && here*mini <= rest; ++here) {
        ll x = calc(rest, mini, here); // ここの割当方法
        ll y = solve(rest-here*mini, mini+1);
        res = (res + x*y%MOD) % MOD;
      }
    }
  }
  return res;
}

int main(void) {
  int N;
  cin >> N >> A >> B >> C >> D;

  REP(i, 1010) {
    cmb[i][0] = 1;
    for(int j = 1; j <= i; ++j) {
      cmb[i][j] = (cmb[i-1][j-1] + cmb[i-1][j]) % MOD;
    }
  }

  memset(memo, -1, sizeof memo);
  ll res = solve(N, A);
  printf("%lld\n", res);
  
  return 0;
}
