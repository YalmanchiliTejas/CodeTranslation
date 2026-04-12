#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  string s;
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    s = "vowel";
  }
  else {
    s = "consonant";
  }
  
  cout << s << endl;
}