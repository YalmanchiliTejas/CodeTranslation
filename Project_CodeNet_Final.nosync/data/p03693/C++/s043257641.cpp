#include <iostream>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int num = 100 * r + 10 * g + b;
  if (num % 4 == 0) cout << "YES";
  else cout << "NO";
}
