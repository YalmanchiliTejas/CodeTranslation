/*  -*- coding: utf-8 -*-
 *
 * s.cc: S - Digit Sum
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

const int MAX_N = 10000;
const int MAX_D = 100;
const int MOD = 1000000007;

/* typedef */

/* global variables */

char s[MAX_N + 4];
int dp[MAX_N + 1][MAX_D];

/* subroutines */

inline void addmod(int &a, int b) { a = (a + b) % MOD; }

/* main */

int main() {
  int d;
  scanf("%s%d", s, &d);
  int n = strlen(s);

  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < d; j++)
      if (dp[i][j])
	for (int k = 0; k <= 9; k++)
	  addmod(dp[i + 1][(j + k) % d], dp[i][j]);

  int sum = 0, b = 0;
  for (int i = n - 1; i >= 0; i--) {
    int di = s[n - 1 - i] - '0';
    int bj = b;
    for (int j = 0; j < di; j++, bj = (bj + 1) % d)
      addmod(sum, dp[i][(d - bj) % d]);
    b = (b + di) % d;
  }
  if (b != 0) addmod(sum, MOD - 1);
  
  printf("%d\n", sum);
  return 0;
}
