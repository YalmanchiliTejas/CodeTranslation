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

const int MAX_N = 300000;
const int MAX_Q = 150000;
const int MAX_E2 = 1 << 20;

const int INF = 1 << 30;

/* typedef */

typedef set<int> si;

struct SegTreeSumMin {
  int n, e2;
  int nodes[MAX_E2], mins[MAX_E2];

  SegTreeSumMin() { clear(); }
  SegTreeSumMin(int _n) { init(_n); clear(); }

  void init(int _n) {
    n = _n;
    for (e2 = 1; e2 < n; e2 <<= 1);
  }

  void clear() {
    //for (int i = 0; i < MAX_E2; i++) nodes[i] = INF;
  }

  int get(int i) { return nodes[e2 - 1 + i]; }

  void set(int i, int v) {
    int j = e2 - 1 + i;
    nodes[j] = mins[j] = v;
    j = (j - 1) / 2;

    for (;;) {
      int j0 = j * 2 + 1, j1 = j0 + 1;
      nodes[j] = nodes[j0] + nodes[j1];
      mins[j] = min(mins[j0], nodes[j0] + mins[j1]);
      if (j == 0) break;
      j = (j - 1) / 2;
    }
  }

  int min_range(int r0, int r1, int k, int i0, int i1) {
    if (r1 <= i0 || i1 <= r0) return INF;
    if (r0 <= i0 && i1 <= r1) return mins[k] + sum_range(0, i0);

    int im = (i0 + i1) / 2;
    int v0 = min_range(r0, r1, k * 2 + 1, i0, im);
    int v1 = min_range(r0, r1, k * 2 + 2, im, i1);

    return min(v0, v1);
  }

  int min_range(int r0, int r1) {
    return min_range(r0, r1, 0, 0, e2);
  }

  int min_all() { return mins[0]; }

  int sum_range(int r0, int r1, int k, int i0, int i1) {
    if (r1 <= i0 || i1 <= r0) return 0;
    if (r0 <= i0 && i1 <= r1) return nodes[k];

    int im = (i0 + i1) / 2;
    int v0 = sum_range(r0, r1, k * 2 + 1, i0, im);
    int v1 = sum_range(r0, r1, k * 2 + 2, im, i1);

    return v0 + v1;
  }

  int sum_range(int r0, int r1) {
    return sum_range(r0, r1, 0, 0, e2);
  }

  int sum_all() { return sum_range(0, n); }
  
  void print() {
    for (int i = 0; i < n; i++) cout << min_range(i, n) << ' ';
    cout << endl;
  }
};

/* global variables */

int n, q;
string str;
int ps[MAX_N];

SegTreeSumMin stsm;
si pcls;

/* main */

int main() {
  cin >> n >> q;
  cin >> str;

  stsm.init(n);
  
  for (int i = 0; i < n; i++) {
    if (str[i] == '(')
      stsm.set(i, 1);
    else {
      stsm.set(i, -1);
      pcls.insert(i);
    }
  }
  
  while (q--) {
    int qi;
    cin >> qi;
    qi--;

    int pqi = stsm.get(qi);
    int r = -pqi;
    stsm.set(qi, r);

    //stsm.print();
    //cout << stsm.min_all() << endl;

    if (pqi == 1) { // '('->')'
      pcls.insert(qi);
      int i = *pcls.begin();
      pcls.erase(pcls.begin());
      stsm.set(i, 1);
      cout << (i + 1) << endl;
    }
    else { // ')'->'('
      pcls.erase(qi);
      //stsm.print();
      
      int i0 = -1, i1 = qi;

      while (i0 + 1 < i1) {
	int i = (i0 + i1) / 2;
	if (stsm.min_range(i, qi) >= 2) i1 = i;
	else i0 = i;
      }
      //printf("i1=%d\n", i1);
      while (stsm.get(i1) != 1) i1++;

      stsm.set(i1, -1);
      pcls.insert(i1);
      cout << (i1 + 1) << endl;
    }
  }
  
  return 0;
}