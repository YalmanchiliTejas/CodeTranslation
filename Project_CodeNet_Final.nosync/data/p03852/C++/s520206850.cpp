#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  
  string ans = "consonant";
  string vowel = "aeiou";
  for (int i = 0; i < vowel.size(); i++) {
    if (c == vowel.at(i)) {
      ans = "vowel";
      break;
    }
  }
  cout << ans << endl;
}
