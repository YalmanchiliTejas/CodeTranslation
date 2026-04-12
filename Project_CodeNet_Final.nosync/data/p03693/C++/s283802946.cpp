#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int r, g, b;
  cin >> r >> g >> b;
  cout << (((g * 10 + b) % 4 == 0) ? "YES" : "NO") << "\n";
  return 0;
}
