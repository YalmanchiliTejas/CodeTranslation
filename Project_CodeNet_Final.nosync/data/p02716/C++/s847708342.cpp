/*  -*- coding: utf-8 -*-
 *
 * f.cc: F - Select Half
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

const int MAX_N = 200000;
const long long LINF = 1LL << 62;

/* typedef */

typedef long long ll;

/* global variables */

int as[MAX_N];
ll dp00[MAX_N + 1], dp01[MAX_N + 1], dp10[MAX_N + 1], dp11[MAX_N + 1];

/* subroutines */

inline void setmax(ll &a, ll b) { if (a < b) a = b; }

/* main */

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", as + i);

  fill(dp00, dp00 + n + 1, -LINF);
  fill(dp01, dp01 + n + 1, -LINF);
  fill(dp10, dp10 + n + 1, -LINF);
  fill(dp11, dp11 + n + 1, -LINF);
  dp01[0] = 0;

  for (int i = 0; i < n; i++) {
    bool ev = ((i & 1) == 0);
    if (dp00[i] > -LINF) {
      if (ev)
	setmax(dp10[i + 1], dp00[i] + as[i]);
      else {
	setmax(dp00[i + 1], dp00[i]);
	setmax(dp11[i + 1], dp00[i] + as[i]);
      }
    }
    if (dp01[i] > -LINF) {
      if (ev) {
	setmax(dp00[i + 1], dp01[i]);
	setmax(dp11[i + 1], dp01[i] + as[i]);
      }
      else
	setmax(dp01[i + 1], dp00[i]);
    }
    if (dp10[i] > -LINF) {
      if (! ev)
	setmax(dp00[i + 1], dp10[i]);
    }
    if (dp11[i] > -LINF) {
      if (ev)
	setmax(dp00[i + 1], dp11[i]);
      else
	setmax(dp01[i + 1], dp11[i]);
    }
  }

  printf("%lld\n", (n & 1) ? max(dp00[n], dp10[n]) : max(dp01[n], dp11[n]));

  return 0;
}
