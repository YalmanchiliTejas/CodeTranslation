#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  int r, g, b;
  cin >> r >> g >> b;

  int x = 100 * r + 10 * g + b;
  if (x % 4 == 0) {
	cout << "YES" << endl;
  }
  else {
	cout << "NO" << endl;
  }

  return (0);
}