/*  -*- coding: utf-8 -*-
 *
 * 3041.cc: 
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
  int n, q;
  scanf("%d%d", &n, &q);

  int h = 0;
  while (q--) {
    int op, k;
    scanf("%d%d", &op, &k);

    if (op == 0) {
      k--;
      printf("%d\n", (h + k) % n + 1);
    }
    else
      h = (h + k) % n;
  }
  return 0;
}

