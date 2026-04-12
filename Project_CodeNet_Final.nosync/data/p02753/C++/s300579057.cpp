/*  -*- coding: utf-8 -*-
 *
 * a.cc: A - Station and Bus
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

const int N = 3;

/* typedef */

/* global variables */

char s[N + 4];

/* subroutines */

/* main */

int main() {
  scanf("%s", s);

  int an = 0, bn = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'A') an++;
    else bn++;
  }

  if (an > 0 && bn > 0) puts("Yes");
  else puts("No");
  return 0;
}
