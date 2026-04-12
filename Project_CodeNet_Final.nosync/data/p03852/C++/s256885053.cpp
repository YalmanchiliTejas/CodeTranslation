#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  string s = "aiueo";
  string a = "consonant";
  for (int i=0; i<5; i++) {
    if (c == s.at(i)) {
      a = "vowel";
      break;
    }
  }
  cout << a << endl;
}