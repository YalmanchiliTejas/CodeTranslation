#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  string v = "aeiou";
  bool flg = false;
  
  for (int i = 0; i < v.size(); i++) {
    if (v.at(i) == c) {
      flg = true;
      break;
    }
  }
  cout << (flg ? "vowel":"consonant") << endl;
}
