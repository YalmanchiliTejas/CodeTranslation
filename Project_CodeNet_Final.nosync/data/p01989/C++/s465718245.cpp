/*  -*- coding: utf-8 -*-
 *
 * 2889.cc: Internet Protocol Address
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

const int MAX_N = 12;
const int M = 4;

/* typedef */

/* global variables */

char s[MAX_N + 4];
int dp[MAX_N + 1][M + 1];

/* subroutines */

/* main */

int main() {
  scanf("%s", s);
  int n = strlen(s);

  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < M; j++)
      if (dp[i][j] > 0) {
	if (s[i] == '0') dp[i + 1][j + 1] += dp[i][j];
	else {
	  int d = 0;
	  for (int k = i; k < n; k++) {
	    d = d * 10 + (s[k] - '0');
	    if (d >= 256) break;
	    dp[k + 1][j + 1] += dp[i][j];
	  }
	}
      }

  printf("%d\n", dp[n][M]);
  return 0;
}

