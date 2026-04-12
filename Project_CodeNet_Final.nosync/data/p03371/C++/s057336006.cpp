#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)

signed main () {
  cin.tie(0);
  cout << setprecision(10);

  int a, b, ab, x, y;
  cin >> a >> b >> ab >> x >> y;


  if(a + b < ab * 2) {
    if(a > ab*2 && b > ab*2) {
      cout << ab * 2 * (x + y) << endl;
    } else if (a > ab*2) {
      cout << ab*2*x + b*y << endl;
    } else if (b > ab*2) {
      cout << a*x + ab*2*y << endl;
    } else {
      cout << a*x + b*y << endl;
    }
  } else {
    if(a > ab*2 && b > ab*2) {
      cout << ab*2 * max(x, y) << endl;
    } else if (a > ab*2) {
      cout << ab*2 * x + b * max((int)0, y-x) << endl;
    } else if (b > ab*2) {
      cout << ab*2 * y + a * max((int)0, x-y) << endl;
    } else {
      int z = min(x, y);
      x -= z;
      y -= z;
      cout << x*a + y*b + z*ab*2 << endl;
    }
  }
}
