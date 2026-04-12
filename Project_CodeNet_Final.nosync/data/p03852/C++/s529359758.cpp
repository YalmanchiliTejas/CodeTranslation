#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "aiueo";
  char c;
  cin >> c;
  int a = 0;

  for (int i = 0; i < 5; i++) {
    if (c == s.at(i))
      a = 1;
  }
  
  if (a == 1)
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
}
