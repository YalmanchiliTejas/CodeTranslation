/*  -*- coding: utf-8 -*-
 *
 * b.cc: B - *e**** ********e* *e****e* ****e**
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

char s[16];

/* subroutines */

/* main */

int main() {
  int n, k;
  scanf("%d%s%d", &n, s, &k);

  char c = s[k - 1];
  for (int i = 0; i < n; i++) putchar((s[i] == c) ? c : '*');
  putchar('\n');
  return 0;
}
