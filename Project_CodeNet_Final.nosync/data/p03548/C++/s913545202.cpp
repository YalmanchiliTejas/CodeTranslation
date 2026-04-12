#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int cnt = 1;
  int len = Y + Z * 2;
  do {
    len += Y + Z;
    if (X < len) {
      break;
    }
    ++cnt;
  } while (X != len);
  cout << cnt << endl;
}