/*  -*- coding: utf-8 -*-
 *
 * d.cc: D: Christmas
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

const int MAX_N = 50;

/* typedef */

typedef long long ll;

/* global variables */

ll bls[MAX_N + 1], pns[MAX_N + 1];

/* subroutines */

ll pn_range(ll x, int n, ll i0) {
  if (x <= i0) return 0;
  if (i0 + bls[n] <= x) return pns[n];

  return
    pn_range(x, n - 1, i0 + 1) +
    pn_range(x,     0, i0 + 1 + bls[n - 1]) +
    pn_range(x, n - 1, i0 + 1 + bls[n - 1] + bls[0]);
}

/* main */

int main() {
  int n;
  ll x;
  scanf("%d%lld", &n, &x);

  bls[0] = pns[0] = 1;
  for (int i = 0; i < n; i++) {
    bls[i + 1] = bls[i] * 2 + 3;
    pns[i + 1] = pns[i] * 2 + 1;
  }
  //for (int i = 0; i <= n; i++) printf("%d: %lld %lld\n", i, bls[i], pns[i]);

  printf("%lld\n", pn_range(x, n, 0));
  return 0;
}
