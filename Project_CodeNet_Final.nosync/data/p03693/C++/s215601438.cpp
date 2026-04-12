#include <iostream>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  string s = to_string(r) + to_string(g) + to_string(b);
  int num = stoi(s);
  if (num % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
