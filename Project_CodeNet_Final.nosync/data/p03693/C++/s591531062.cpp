#include <iostream>
using namespace std;

int main()
{
  int a, b, c; cin >> a >> b >> c;
  cout << ((100*a + 10*b + c) % 4 == 0 ? "YES" : "NO");
  return 0;
}