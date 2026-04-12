#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, x, y;
  cin >> n;

  x = 800 * n;
  m = (n - n%15) / 15;
  y = 200 * m;

  cout << x - y << endl;
}
