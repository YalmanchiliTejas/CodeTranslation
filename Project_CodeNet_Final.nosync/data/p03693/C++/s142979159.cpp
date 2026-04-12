#include <bits/stdc++.h>

using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int combined = r * 100 + g * 10 + b;
  if (combined % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

