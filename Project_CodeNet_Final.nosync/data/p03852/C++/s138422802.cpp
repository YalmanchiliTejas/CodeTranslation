#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  
  const string vowel = "aeiou";
  string result; 
  for (int i = 0; i < vowel.size(); i++) {
    if (c == vowel.at(i)) {
      result = "vowel";
      break;
    }
    else {
      result = "consonant";
    }
  }
  
  cout << result << endl;
  
  return 0;
}

