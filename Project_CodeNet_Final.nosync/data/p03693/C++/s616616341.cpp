#include <bits/stdc++.h>
using namespace std;

int main()
{
  int r, g, b;
  cin >> r >> g >> b;
  if ((r * 100 + g * 10 + b) % 4) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  return 0;
}