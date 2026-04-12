#include <bits/stdc++.h>

using namespace std;

int main()
{
  int X, Y, Z; cin >> X >> Y >> Z;

  int i = 0;
  while (i*Y+(i+1)*Z <= X) i++;
  cout << i-1;
}