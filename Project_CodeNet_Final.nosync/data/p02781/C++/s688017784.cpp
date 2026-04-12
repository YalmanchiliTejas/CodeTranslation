/*  -*- coding: utf-8 -*-
 *
 * e.cc: E - Almost Everywhere Zero
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

const int MAX_N = 100;
const int MAX_K = 3;

/* typedef */

typedef long long ll;
typedef vector<int> vi;
typedef queue<int> qi;
typedef pair<int,int> pii;

/* global variables */

char s[MAX_N + 4];
int es[MAX_K + 1];

/* subroutines */

inline int nck(int n, int k) {
  if (n < k) return 0;
  if (k == 0) return 1;
  if (k == 1) return n;
  if (k == 2) return n * (n - 1) / 2;
  return n * (n - 1) * (n - 2) / 6;
}

/* main */

int main() {
  int k;
  scanf("%s%d", s, &k);
  int n = strlen(s);

  es[0] = 1;
  for (int i = 0; i < k; i++) es[i + 1] = es[i] * 9;

  int sum = 0;
  for (int i = 0; k > 0 && i < n; i++) {
    int ai = s[i] - '0';
    if (ai > 0) {
      sum += es[k] * nck(n - 1 - i, k);
      sum += (ai - 1) * es[k - 1] * nck(n - 1 - i, k - 1);
      k--;
      if (k == 0) sum++;
    }
  }

  printf("%d\n", sum);
  return 0;
}
