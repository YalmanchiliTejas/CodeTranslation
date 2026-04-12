#include <bits/stdc++.h>
using namespace::std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define dump(x) cout << (x) << endl;

int main() {
  int a, b, ab, x, y;
  cin >> a >> b >> ab >> x >> y;
  ab *= 2;
  int sum = 0;
  if (a+b > ab) {
    sum += ab*min(x, y);
  }
  else {
    sum += (a+b)*min(x, y);
  }
  if (x > y) {
    if (a < ab) {
      sum += a*(x-y);
    }
    else {
      sum += ab*(x-y);
    }
  }
  else if (x < y) {
    if (b < ab) {
      sum += b*(y-x);
    }
    else {
      sum += ab*(y-x);
    }
  }
  dump(sum);
  return 0;
}
