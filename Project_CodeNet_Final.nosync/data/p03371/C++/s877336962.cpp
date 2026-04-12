/*  -*- coding: utf-8 -*-
 *
 * a.cc: C: Half and Half
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

/* global variables */

/* subroutines */

/* main */

int main() {
  int a, b, c, x, y;
  scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);

  int sum = 0;

  if (x > 0 && y > 0 && a + b >= 2 * c) {
    int xy = min(x, y);
    sum += xy * (2 * c);
    x -= xy, y -= xy;
  }

  if (x > 0 && a >= 2 * c) {
    sum += x * (2 * c);
    x = 0;
  }

  if (y > 0 && b >= 2 * c) {
    sum += y * (2 * c);
    y = 0;
  }

  sum += a * x + b * y;

  printf("%d\n", sum);
  return 0;
}
