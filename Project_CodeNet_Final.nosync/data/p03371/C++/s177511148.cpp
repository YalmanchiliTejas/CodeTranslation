#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if (x > y) {
    swap(x, y);
    swap(a, b);
  }
  cout <<  x * min(a+b, 2*c) + (y-x) * min(b, 2*c) << endl;

  return 0;
}

