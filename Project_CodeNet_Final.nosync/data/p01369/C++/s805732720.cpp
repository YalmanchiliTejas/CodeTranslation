#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
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

enum {L, R};

const int keys[] = {
//a, b, c, d, e, f, g, h, i, j, k, l, m, n,
  L, L, L, L, L, L, L, R, R, R, R, R, R, R,
//o, p, q, r, s, t, u, v, w, x, y, z
  R, R, L, L, L, L, R, L, L, L, R, L
};

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main() {
  for (;;) {
    string line;
    cin >> line;
    if (line == "#") break;

    int len = line.length();
    int prv = keys[line[0] - 'a'];
    int count = 0;

    for (int i = 1; i < len; i++) {
      int cur = keys[line[i] - 'a'];
      if (prv != cur) count++;
      prv = cur;
    }

    cout << count << endl;
  }

  return 0;
}