#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string s;
  cin >> s;
  bool yes = false;
  if (s[0] != s[1] or s[0] != s[2])
    yes = true;
  if (s[1] != s[2])
    yes = true;
  if (yes)
    cout << "Yes";
  else
    cout << "No";
}