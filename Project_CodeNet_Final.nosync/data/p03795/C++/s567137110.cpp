/*  -*- coding: utf-8 -*-
 *
 * a.cc: A: Restaurant
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
  int n;
  cin >> n;
  int x = n * 800;
  int y = (n / 15) * 200;
  printf("%d\n", x - y);
  return 0;
}
