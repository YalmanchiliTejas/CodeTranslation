#include <bits/stdc++.h>

using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int n = X / (Y + Z);
  if ((Y + Z) * n + Z <= X) {
    cout << n;
  } else {
    cout << max(n - 1, 0);
  }
  return 0;
}
