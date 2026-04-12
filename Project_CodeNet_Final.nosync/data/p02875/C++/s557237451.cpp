/*  -*- coding: utf-8 -*-
 *
 * c.cc: C - Neither AB nor BA
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

const int MAX_N = 10000000;
const int MOD = 998244353;

/* typedef */

typedef long long ll;

/* global variables */

int e2s[MAX_N + 1], cns[MAX_N + 1];

/* subroutines */

inline void addmod(int &a, int b) { a = (a + b) % MOD; }

int powmod(int a, int n) {  // a^n % MOD
  int pm = 1;
  while (n > 0) {
    if (n & 1) pm = (ll)pm * a % MOD;
    a = (ll)a * a % MOD;
    n >>= 1;
  }
  return pm;
}

/* main */

int main() {
  int n;
  scanf("%d", &n);

  int e3 = powmod(3, n);

  e2s[0] = 1;
  for (int i = 1; i <= n; i++) e2s[i] = (ll)e2s[i - 1] * 2 % MOD;

  cns[0] = 1;
  for (int i = 1; i <= n / 2; i++)
    cns[i] = (ll)cns[i - 1] * (n + 1 - i) % MOD * powmod(i, MOD - 2) % MOD;

  int sum = 0;
  for (int i = n / 2 + 1; i <= n; i++) {
    int d = (ll)cns[n - i] * e2s[n - i] % MOD;
    addmod(sum, d);
  }

  int ans = (e3 + MOD - (ll)sum * 2 % MOD) % MOD;
  printf("%d\n", ans);
  return 0;
}
