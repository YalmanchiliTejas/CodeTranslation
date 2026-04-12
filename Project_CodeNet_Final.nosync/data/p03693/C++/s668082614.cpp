#include <iostream>

using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;

  const char* out = ((r*100 + g*10 + b) % 4 == 0) ? "YES": "NO";
  cout << out << endl;
  return 0;
}