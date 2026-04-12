/*
 * b.cc: 
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

const int MAX_VN = 100000;
const int MAX_EN = 200000;

/* typedef */

typedef vector<int> vi;

/* global variables */

int as[MAX_VN];
bool used[MAX_VN][26];
vi nbrs[MAX_VN];

/* subroutines */

/* main */

int main() {
  int vn, en;
  cin >> vn >> en;

  for (int i = 0; i < vn; i++) {
    char ai;
    cin >> ai;
    as[i] = (ai == '?') ? -1 : ai - 'a';
  }

  for (int i = 0; i < en; i++) {
    int si, ti;
    cin >> si >> ti;

    nbrs[si].push_back(ti);
    if (as[ti] >= 0) used[si][as[ti]] = true;

    nbrs[ti].push_back(si);
    if (as[si] >= 0) used[ti][as[si]] = true;
  }

  for (int i = 0; i < vn; i++) {
    if (as[i] < 0) {
      for (int j = 0; j < 26; j++)
	if (! used[i][j]) {
	  as[i] = j;
	  break;
	}

      vi &nbri = nbrs[i];
      for (vi::iterator vit = nbri.begin(); vit != nbri.end(); vit++)
	used[*vit][as[i]] = true;

    }

    putchar(as[i] + 'a');
  }
  putchar('\n');

  return 0;
}
