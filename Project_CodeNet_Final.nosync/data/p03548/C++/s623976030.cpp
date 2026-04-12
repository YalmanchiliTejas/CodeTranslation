#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int x,y,z;
  cin >> x >> y >> z;
  int ans = 1;
  ans += (x-y-2*z)/(y+z);
  cout << ans << endl;
  return 0;
}