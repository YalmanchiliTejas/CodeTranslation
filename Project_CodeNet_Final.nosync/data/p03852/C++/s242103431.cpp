#include <bits/stdc++.h>

using namespace std;

int main(void) {
  string vowel = "aeiou";
  char c; cin >> c;

  for (auto it = vowel.begin(); it != vowel.end(); it++) {
    if (*it == c) {
      cout << "vowel" << endl;
      return 0;
    }
  }

  cout << "consonant" << endl;
  return 0;
}