#include <bits/stdc++.h>

using namespace std;

int main() {
  char c;
  cin >> c;

  bool vowel = false;

  for (int i = 0; i < 5; i++) {
    if ("aiueo"s.at(i) == c) {
      cout << "vowel" << endl;
      vowel = true;
    }
  }
  if (vowel == false) {
    cout << "consonant" << endl;
  }
}
