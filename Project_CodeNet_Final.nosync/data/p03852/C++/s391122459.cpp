#include <bits/stdc++.h>
using namespace std;

int main() {
  string main = "aiueo";
  char c;
  cin >> c;
  int i, flag = 0;
  for(i=0; i<5; i++){
    if(c == main.at(i)){
      flag = 1; break;
    }
  }
  if(flag) cout << "vowel" << endl;
  else cout << "consonant" << endl;
  
  return 0;
  
}
