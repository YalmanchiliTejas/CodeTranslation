/*  -*- coding: utf-8 -*-
 *
 * a.cc: A: Kaiden
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

/* typedef */

typedef long long ll;

/* global variables */

/* subroutines */

/* main */

int main() {
  ll k, a, b;
  cin >> k >> a >> b;

  if (a >= k) puts("1");
  else if (a <= b) puts("-1");
  else printf("%lld\n", (k - a + a - b - 1) / (a - b) * 2 + 1);

  return 0;
}
