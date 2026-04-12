#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>

#define INF 1000000000
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

using namespace std;

int a,b,c,x,y;
int ans = 0;
int tt1, tt2, tt3;

int main() {
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

  tt1 = a * x + b * y;
  int s;
  if (x > y) {
    tt2 = 2 * c * y;
    s = (x - y) * a;
    tt2 += s;
  } else {
    tt2 = 2 * c * x;
    s = (y - x) * b;
    tt2 += s;
  }

  tt3 = (x > y) ? 2 * c * x : 2 * c * y;

  if (tt1 < tt2 && tt1 < tt3) {
    cout << tt1 << endl;
  } else if (tt2 < tt1 && tt2 < tt3) {
    cout << tt2 << endl;
  } else {
    cout << tt3 << endl;
  }
}
