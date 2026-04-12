#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  
  string v = "aeiou";
  int is_vowel = 0;
  // ここにプログラムを追記
  for(int i=0; i<v.size(); i++) {
    if(v.at(i) == c) {
        is_vowel = 1;
        break;
    }
  }
  
  if (is_vowel) {
      cout << "vowel";
  } else {
      cout << "consonant";
  }
  cout << endl;

    
}
