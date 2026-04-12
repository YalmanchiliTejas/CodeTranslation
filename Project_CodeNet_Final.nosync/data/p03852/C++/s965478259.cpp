#include <bits/stdc++.h>
using namespace std;

int main() {
  char c; cin >> c;
  if (string("aeiou").find(c) == string::npos) {
    cout << "consonant";
  } else {
    cout << "vowel";
  }
}
