#include <bits/stdc++.h>
using namespace std;

int main() {
  string p = "aeiou";
  char c;
  cin >> c;
  int i; 
    
  for (i = 0; i < 5; i++) {
    if (c == p.at(i)) {
      cout << "vowel" << endl;
      break;
    }
  }
  
  if (i == 5) {
    cout << "consonant" << endl;
  }
}
  
