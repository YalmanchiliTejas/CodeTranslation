#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, y, z;
  cin >> x >> y >> z;
  
  int cnt = 0;
  x -= z * 2;
  cnt += x / (y+z);
  if (x%(y+z) == y) cnt++;
  
  cout << cnt << endl;
}