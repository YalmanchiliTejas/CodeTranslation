#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  bool ans = 0;
  if (c == 'a' || c == 'i') {
    ans = 1;
  }
  else if (c == 'u' || c == 'e') {
    ans = 1;
  }
  else if (c == 'o') {
    ans = 1;
  }
  if (ans) {
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
}