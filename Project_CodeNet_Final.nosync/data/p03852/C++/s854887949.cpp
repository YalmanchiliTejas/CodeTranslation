#include <bits/stdc++.h>
using namespace std;

int main() {
  char S;
  cin >> S;
  string T = "aeiou";
  string U;
  
  for (int i=0; i < T.size(); i++){
    if ( S == T.at(i)){
      U = "vowel";
      break;
    }
    else {
      U = "consonant";
    }
  }
  cout << U << endl;
      

  // ここにプログラムを追記
  
 
}
