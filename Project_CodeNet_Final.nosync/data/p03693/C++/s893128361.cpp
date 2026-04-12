
#include <iostream>
using namespace std;

int main()
{
  int r, g, b;
  cin >> r >> g >> b;
  cout << ((0 == (10*g + b)%4) ? "YES" : "NO");
  return 0;
}
