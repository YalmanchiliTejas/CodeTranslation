#include <bits/stdc++.h>

using namespace std;

int main()
{
  string a, b, c, d;

  cin >> d;

  a = d[0];

  b = d[1];

  c = d[2];

  if (a == b && b == c)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
}