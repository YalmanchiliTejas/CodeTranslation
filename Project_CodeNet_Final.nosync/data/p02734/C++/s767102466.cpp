/*  -*- coding: utf-8 -*-
 *
 * f.cc: F - Knapsack for All Segments
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

const int MAX_N = 3000;
const int MAX_S = 3000;
const int MOD = 998244353;

/* typedef */

/* global variables */

int as[MAX_N];
int dp0[MAX_N + 1][MAX_S + 1], dp1[MAX_N + 1][MAX_S + 1];

/* subroutines */

inline void addmod(int &a, int b) { a = (a + b) % MOD; }

/* main */

int main() {
  int n, s;
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; i++) scanf("%d", as + i);

  dp0[0][0] = 1;
  for (int i = 0; i < n; i++) {
    int ai = as[i];
    for (int j = 0; j <= s; j++) {
      if (dp0[i][j]) {
	addmod(dp0[i + 1][j], dp0[i][j] + 1);
	if (j + ai <= s)
	  addmod(dp1[i + 1][j + ai], dp0[i][j]);
      }
      if (dp1[i][j]) {
	addmod(dp1[i + 1][j], dp1[i][j]);
	if (j + ai <= s)
	  addmod(dp1[i + 1][j + ai], dp1[i][j]);
      }
    }
  }

  int sum = 0;
  for (int i = 0; i <= n; i++) addmod(sum, dp1[i][s]);

  printf("%d\n", sum);
  return 0;
}
