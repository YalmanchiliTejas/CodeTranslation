#include <bits/stdc++.h>
using namespace std;

int main() {
  char s;
  cin >> s;
  
  string f = "consonant";
  string V = "aeiou";
  
  for (int i=0; i< V.size(); i++){
    if (s == V.at(i)){
      f = "vowel";
      break;
    }
  }
  cout << f << endl;
}
