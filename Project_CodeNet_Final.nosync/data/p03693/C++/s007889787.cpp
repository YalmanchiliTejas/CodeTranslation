#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int num = g * 10 + b;
  cout << ((num % 4 == 0) ? "YES" : "NO") << endl;
  return 0;
}