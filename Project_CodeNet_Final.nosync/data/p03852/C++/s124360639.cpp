#include <bits/stdc++.h>
using namespace std;

int main() {
  string V = "aiueo";
  char S;
  int flag;
  cin >> S;
  for (int i = 0; i < 5 ;i++ ) {
  	if (S == V.at(i)) { 
      cout << "vowel" << endl;
      break;
    }
    else if (i == 4) {
      cout << "consonant" << endl;
    }
    
  }
 
}