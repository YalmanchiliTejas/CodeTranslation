#include <bits/stdc++.h>
using namespace std; 

int main() {
  
  string v = "aeiou";

  char c;
  cin >> c;
  
  string ans = "consonant";
  for(int i=0; i<5; i++){
    if (v.at(i) == c) ans = "vowel";
  }
  
  cout << ans << endl;
  
  
}