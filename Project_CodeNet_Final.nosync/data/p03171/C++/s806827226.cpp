/*  -*- coding: utf-8 -*-
 *
 * l.cc: L - Deque
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

/* typedef */

typedef long long ll;

/* global variables */

int as[MAX_N];
ll dp[MAX_N][MAX_N];

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", as + i), dp[i][i] = as[i];

  for (int l = 1; l < n; l++)
    for (int i = 0, j = l; j < n; i++, j++)
      dp[i][j] = max(as[i] - dp[i + 1][j], as[j] - dp[i][j - 1]);

  printf("%lld\n", dp[0][n - 1]);
  return 0;
}
