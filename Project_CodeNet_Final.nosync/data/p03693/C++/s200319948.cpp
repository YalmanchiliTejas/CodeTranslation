#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int r, g, b;
  cin >> r >> g >> b;

  int n = b + g * 10 + r * 100;
  cout << (n % 4 == 0 ? "YES" : "NO") << '\n';
  return 0;
}