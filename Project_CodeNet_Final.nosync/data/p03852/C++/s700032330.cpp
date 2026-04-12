#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;
  cin >> c;

  const string vowel = "aeiou";
  bool ans = false;

  for(int i = 0; i < 5; i++) {
    if(c == vowel.at(i)) {
      ans = true;
    }
  }

  if(ans == true) {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
  return 0;
}