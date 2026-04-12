#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  char c;
  cin >> c;
  switch (c) {
  case 'a':
  case 'i':
  case 'u':
  case 'e':
  case 'o':
    cout << "vowel\n";
    break;
  default:
    cout << "consonant\n";
  }
  return 0;
}
