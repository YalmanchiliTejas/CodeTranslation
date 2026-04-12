#include <iostream>
using namespace std;

int main()
{
  int r, g, b, total;
  cin >> r >> g >> b;
  total = r * 100 + g * 10 + b;
  cout << (0 == total % 4 ? "YES" : "NO") << endl;
  return 0;
}