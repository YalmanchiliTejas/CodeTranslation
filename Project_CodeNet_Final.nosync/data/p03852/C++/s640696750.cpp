#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string b = "aeiou";

  char c;
  cin >> c;

  for (int i = 0; i < 5; ++i) {
    if (c == b[i]) {
      cout << "vowel\n";
      return (0);
    }
  }

  cout << "consonant\n";

  return (0);
}
