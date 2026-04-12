#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  switch (s[0]) {
    case 'a':
    case 'i':
    case 'u':
    case 'e':
    case 'o':
      cout << "vowel" << endl;
      break;
    default:
      cout << "consonant" << endl;
      break;
  }
}
