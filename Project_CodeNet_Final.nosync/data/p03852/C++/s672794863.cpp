#include <bits/stdc++.h>
using namespace std;
int main()
{
  char c;
  cin >> c;

  string s = "aeiou", t = "consonant";
  for (int i = 0; i < 6; i++) {
    if (c == s[i]) t = "vowel";
  }

  cout << t << endl;

  return 0;
}
