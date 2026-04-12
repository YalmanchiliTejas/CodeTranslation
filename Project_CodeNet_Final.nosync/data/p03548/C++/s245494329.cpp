#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z, cnt = 0, dist;
  cin >> x >> y >> z;
  dist = 0;
  while (1) {
    cnt++;
    dist += y + z;
    if ( (x - dist) < (y + 2 * z) ) break;
  }

  cout << cnt << endl;

  return 0;

}