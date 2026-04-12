#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;

  while (cin >> c) {
    if (strchr("aeiou", c)) {
      cout << "vowel" << endl;
    } else {
      cout << "consonant" << endl;
    }
  }
}