#include <bits/stdc++.h>
using namespace std;

/* define const */

/* finish defineing const */

int main()
{
  string s;
  cin >> s;

  bool f = false;
  char c = s[0];
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    f = true;

  if (f) cout << "vowel" << endl;
  else cout << "consonant" << endl;
}