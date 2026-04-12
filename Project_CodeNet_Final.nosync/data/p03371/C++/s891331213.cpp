#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;

int main() {
  ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  
  if (a + b <= c * 2)
    cout << a * x + b * y << endl;
  else {
    if (x > y)
      cout << min(a, c * 2) * (x - y) + 2 * c * y << endl;
    else
      cout << min(b, c * 2) * (y - x) + 2 * c * x << endl;
  }
  
  return 0;
}
