#include <bits/stdc++.h>
using namespace std;

int main() {
  char x;
  cin >> x;
  string str = "aiueo";
  bool p = false;
  
  for (int i = 0; i < str.size(); i++){
    if ( x == str.at(i)) {
      p = true;
      break;
    }
  }
  
  if (p) cout << "vowel" <<endl;
  else cout << "consonant" << endl;
  
 }
