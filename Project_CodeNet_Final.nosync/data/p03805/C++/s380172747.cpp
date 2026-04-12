/*  -*- coding: utf-8 -*-
 *
 * c.cc: C: One-stroke Path
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

const int MAX_N = 8;
const int NBITS = 1 << MAX_N;

/* typedef */

typedef vector<int> vi;
typedef queue<int> qi;
typedef pair<int,int> pii;

/* global variables */

vi nbrs[MAX_N];
int dp[NBITS][MAX_N];

/* subroutines */

/* main */

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    nbrs[a].push_back(b);
    nbrs[b].push_back(a);
  }

  int nbits = 1 << n;
  dp[1][0] = 1;

  for (int bits = 1; bits < nbits; bits++)
    for (int u = 0; u < n; u++)
      if (dp[bits][u] > 0) {
	vi &nbru = nbrs[u];
	for (vi::iterator vit = nbru.begin(); vit != nbru.end(); vit++) {
	  int &v = *vit, vb = 1 << v;
	  if (! (bits & vb)) dp[bits | vb][v] += dp[bits][u];
	}
      }

  int sum = 0;
  for (int i = 0; i < n; i++) sum += dp[nbits - 1][i];
  printf("%d\n", sum);
  return 0;
}
