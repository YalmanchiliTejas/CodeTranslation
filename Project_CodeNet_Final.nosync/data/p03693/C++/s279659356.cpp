#include <iostream>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int x = 10*g	+ b;
  cout << (x % 4 == 0 ? "YES" : "NO") << endl;
}