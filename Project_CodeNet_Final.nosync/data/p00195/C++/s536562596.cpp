#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<30;

int main() {
  int a,b;
  int i = 0;
  int res, ma = 0;
  while(cin>>a>>b,a+b) {
    if (ma < a + b) {
      ma = a + b;
      res = i;
    }
    ++i;
    if (i==5) {
      i = 0;
      printf("%c %d\n", 'A' + res, ma);
      ma = 0;
    }
  }
}