/*  -*- coding: utf-8 -*-
 *
 * e.cc: E - Cell Distance
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_L = 200000;
const int MOD = 1000000007;

/* typedef */

typedef long long ll;

/* global variables */

ll fracs[MAX_L + 1];

/* subroutines */

ll powmod(ll a, int n) {  // a^n % MOD
  ll pm = 1;
  while (n > 0) {
    if (n & 1) pm = (pm * a) % MOD;
    a = (a * a) % MOD;
    n >>= 1;
  }
  return pm;
}

inline ll invmod(ll a) { return powmod(a, MOD - 2); }

inline ll nck(int n, int k) {  // nCk % MOD
  return fracs[n] * invmod(fracs[n - k]) % MOD * invmod(fracs[k]) % MOD;
}

ll calc(int n, int m) {
  ll sum = 0;
  for (int d = 1; d < n; d++)
    sum = (sum + (ll)d * (n - d) % MOD) % MOD;
  return sum * m % MOD * m % MOD;
}

/* main */

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  int l = n * m - 2;
  fracs[0] = 1;
  for (int i = 1; i <= l; i++)
    fracs[i] = fracs[i - 1] * i % MOD;

  ll ans = (calc(n, m) + calc(m, n)) % MOD * nck(l, k - 2) % MOD;
  printf("%lld\n", ans);
  
  return 0;
}
