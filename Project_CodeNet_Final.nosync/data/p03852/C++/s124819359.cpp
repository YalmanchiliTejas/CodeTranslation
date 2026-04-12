#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;
  cin >> c;
 
  // 1の数を表す変数
  const string vowel = "aeiou";

  bool checkC = false;
  
  for (int i = 0; i < 5; i++) {
      if (vowel.at(i) == c) {
        checkC = true; 
      }
  }
  
  if(checkC){
      cout << "vowel" << endl;
  } else {
     cout << "consonant" << endl;
  }
}