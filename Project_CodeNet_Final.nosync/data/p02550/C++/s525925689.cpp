/*  -*- coding: utf-8 -*-
 *
 * e.cc: E - Sequence Sum
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

const int MAX_M = 100000;

/* typedef */

typedef long long ll;

/* global variables */

int as[MAX_M + 1], rs[MAX_M];
ll ass[MAX_M + 2];

/* subroutines */

/* main */

int main() {
  ll n;
  int x, m;
  scanf("%lld%d%d", &n, &x, &m);
  x %= m;

  memset(rs, -1, sizeof(rs));
  rs[x] = 0;
  as[0] = x;
  int l1 = 0;
  for (;;) {
    l1++;
    as[l1] = (ll)as[l1 - 1] * as[l1 - 1] % m;
    if (rs[as[l1]] >= 0) break;
    rs[as[l1]] = l1;
  }
  int l0 = rs[as[l1]];
  //printf("l0=%d, l1=%d\n", l0,l1);
  //for (int i = 0; i <= l; i++) printf("%d ", as[i]); putchar('\n');

  for (int i = 0; i <= l1; i++) ass[i + 1] = ass[i] + as[i];

  ll ans;
  if (n <= l1)
    ans = ass[n];
  else {
    int l = l1 - l0;
    ll a = (n - l0) / l;
    int b = (n - l0) % l;
    ans = (ass[l1] - ass[l0]) * a + ass[l0 + b];
  }

  printf("%lld\n", ans);
  return 0;
}
