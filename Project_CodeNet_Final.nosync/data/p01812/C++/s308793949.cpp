/*  -*- coding: utf-8 -*-
 *
 * 2709.cc: Dark Room
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

/* typedef */

typedef vector<int> vi;
typedef queue<vi> qvi;
typedef map<vi,int> mvii;

/* global variables */

bool dks[MAX_N];
int vs[MAX_N][MAX_N];
mvii dists;

/* subroutines */

/* main */

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  vi st;
  for (int i = 0; i < m; i++) {
    int di;
    scanf("%d", &di);
    di--;
    st.push_back(di);
    dks[di] = true;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++)
      scanf("%d", &vs[i][j]), vs[i][j]--;

  qvi q;
  q.push(st);
  dists[st] = 0;
  int mind = -1;

  while (! q.empty()) {
    vi u = q.front(); q.pop();
    int un = u.size(), vd = dists[u] + 1;

    for (int i = 0; i < k; i++) {
      vi v;
      for (int j = 0; j < un; j++) {
	int &vj = vs[u[j]][i];
	if (dks[vj]) v.push_back(vj);
      }

      if (v.empty()) {
	printf("%d\n", vd);
	return 0;
      }
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());

      if (dists.find(v) == dists.end()) {
	dists[v] = vd;
	q.push(v);
      }
    }
  }

  return 0;
}