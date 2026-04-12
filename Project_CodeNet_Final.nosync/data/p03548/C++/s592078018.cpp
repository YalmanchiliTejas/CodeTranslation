#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;

  int n = 1;

  while (true) {
    int tmp = Y * n + Z * (n + 1);
    if (tmp > X) {
      break;
    }
    n++;
  }
  cout << (n - 1) << endl;
}