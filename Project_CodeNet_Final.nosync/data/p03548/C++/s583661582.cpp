#include <bits/stdc++.h>

using namespace std;

int x, y, z;

void input()
{
  cin >> x;
  cin >> y;
  cin >> z;
}

void solve()
{
  int res = 0;
  for(int i = z; i <= x-(y+z); i += y+z)
  {
    res++;
  }
  cout << res;
}

int main()
{
  input();
  solve();
  return 0;
}