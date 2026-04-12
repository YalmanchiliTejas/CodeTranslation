#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int sum = Z, cnt = 0;

  for (int i = 0; ; i++) {
    sum += Y + Z;
    if (X < sum) {
      cnt = i;
      break;
    }
  }

  cout << cnt << endl;

  return 0;
}
