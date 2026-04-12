#include <iostream>
#include <cmath>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int solve(const int x, const int y, const int z)
{
  int c = x / (y + z);
  int sum = x - c * (y + z) - z;
  if (sum >= 0) return c;
  else return --c;
}

int main()
{
  int x, y, z;
  cin >> x >> y >> z;
  cout << solve(x, y, z) << endl;
}
