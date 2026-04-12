#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y, o = INT_MAX;
  cin >> a >> b >> c >> x >> y;
  for(int i = 0; i <= max(x, y); i++)
    o = min(o, max(0, (x - i)) * a + max(0, (y - i)) * b + i * 2 * c);
  cout << o << endl;
}