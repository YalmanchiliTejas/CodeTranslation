#include <bits/stdc++.h>
using namespace std;

int main() {
  char c ;
  bool s = false;
  string str = "aiueo";
  cin >> c;
  for (int i = 0; i < str.size(); i++) {
    if (str.at(i) == c) {
      cout << "vowel" << endl;
      s = true;
      break;
    }
  }
  if (s == false)
    cout << "consonant" << endl;
}
