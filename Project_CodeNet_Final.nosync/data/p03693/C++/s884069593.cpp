#include <bits/stdc++.h>
using namespace std;

int main()
{
  int r, g, b;
  string s = "NO";
  cin >> r >> g >> b;
  if ((10 * g + b) % 4 == 0)
    s = "YES";
  cout << s << endl;
}