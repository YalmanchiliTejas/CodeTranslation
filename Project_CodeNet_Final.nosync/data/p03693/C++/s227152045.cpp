/*  -*- coding: utf-8 -*-
 *
 * a.cc: A: RGB Cards
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
  int r, g, b;
  cin >> r >> g >> b;

  if ((r * 100 + g * 10 + b) % 4 == 0) puts("YES");
  else puts("NO");
  return 0;
}
