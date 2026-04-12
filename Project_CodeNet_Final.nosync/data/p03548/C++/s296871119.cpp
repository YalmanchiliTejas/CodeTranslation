#include <iostream>

using namespace std;

int main()	{
  int x, y, z;
  cin >> x >> y >> z;
  int res = 0;
  // if there are n people, there are n * y and (n + 1) * z gaps
  while (res * y + (res + 1) * z <= x)	res++;
  if (res * y + (res + 1) * z > x) res--;
  cout << res << endl;
  return 0;
}