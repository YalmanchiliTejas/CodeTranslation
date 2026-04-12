#include <bits/stdc++.h>

using namespace std;

int main()
{
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int res = 0;
  int pos = Z;
  while (pos + Y + Z <= X)
  {
    res++;
    pos += Z + Y;
  }
  cout << res;
}
