#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int sum = 0;
  int cnt = 0;
  x -= (z * 2);
  while (true) {
    sum += y;
    cnt++;
    if ((x - sum) >= y + z) {
      sum += z;
    } else {
      break;
    }
  }
  cout << cnt << endl;
}