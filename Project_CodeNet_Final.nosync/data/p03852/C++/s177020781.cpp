#include <bits/stdc++.h>
using namespace std;

int main() {
  char x;
  cin >> x;
  string vowel = "aiueo";
  for (int i = 0; true; i++) {
    if (vowel.at(i) == x) {
      cout << "vowel" << endl;
      break;
    }
    if (i == 4) {
      cout << "consonant" << endl;
      break;
    }
  }
}