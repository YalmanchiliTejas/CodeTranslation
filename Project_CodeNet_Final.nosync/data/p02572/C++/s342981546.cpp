/*  -*- coding: utf-8 -*-
 *
 * c.cc: C - Sum of product of pairs
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

const int MOD = 1000000007;

/* typedef */

typedef long long ll;

/* global variables */

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);

  int sum = 0, asum = 0;
  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    sum = (sum + (ll)asum * ai % MOD) % MOD;
    asum = (asum + ai) % MOD;
  }

  printf("%d\n", sum);
  return 0;
}
