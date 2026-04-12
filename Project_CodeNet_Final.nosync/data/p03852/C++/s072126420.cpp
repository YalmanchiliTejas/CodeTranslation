#include <bits/stdc++.h>
using namespace std;

int main()
{
  string c;
  cin >> c;
  cout << (regex_match(c, regex("[aiueo]")) ? "vowel" : "consonant") << endl;
}
