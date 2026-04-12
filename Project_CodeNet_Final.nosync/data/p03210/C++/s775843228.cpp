#include <bits/stdc++.h>
using namespace std;

int main() {
  int X; cin >> X;
  if (X % 2 == 0 || X % 8 == 1) {
    cout << "NO" << endl;
  }
  else cout << "YES" << endl;
  return 0;
}