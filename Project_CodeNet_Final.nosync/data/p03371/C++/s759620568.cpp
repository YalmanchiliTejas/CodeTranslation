#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  if (a + b <= c*2) {
    cout << a*x + b*y << endl;
    return 0;
  }
  if (x == y) {
    cout << 2*c*x << endl;
  } else if (x > y) {
    cout << 2*c*y + (x-y) * min(a,2*c) << endl;
  } else if (x < y) {
    cout << 2*c*x + (y-x) * min(b,2*c) << endl;
  }
  return 0;
}