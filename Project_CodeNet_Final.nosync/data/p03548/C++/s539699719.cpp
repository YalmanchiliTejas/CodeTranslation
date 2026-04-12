#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int x, y, z;
  cin >> x >> y >> z;
  x -= z;
  cout << x / (y + z) << '\n';
  return 0;
}