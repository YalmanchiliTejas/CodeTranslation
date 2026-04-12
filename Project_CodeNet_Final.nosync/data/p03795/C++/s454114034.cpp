#include <iostream>
using namespace std;

signed main()
{
  int n;
  int w;

  cin >> n;
  w = n / 15;

  cout << n * 800 - w * 200 << endl;

  return (0);
}