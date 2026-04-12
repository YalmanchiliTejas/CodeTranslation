#include <bits/stdc++.h>
using namespace std;

int main(){
  char c;
  cin >> c;
  string res = "consonant";

  if(c == 'a' ||
     c == 'i' ||
     c == 'u' ||
     c == 'e' ||
     c == 'o'
     ){
       res = "vowel";
  }
  cout << res << endl;
}
