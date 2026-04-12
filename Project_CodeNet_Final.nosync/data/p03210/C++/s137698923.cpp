#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int X;
  cin >> X;
  string ans = "NO";
  if (X == 3 || X == 7 || X == 5)
    ans = "YES";
  cout << ans << endl;

  return 0;
}