#include <bits/stdc++.h>
using namespace std;

int main(){
  char c;
  bool a,i,u,e,o;

  cin >> c;

  a = c == 'a';
  i = c == 'i';
  u = c == 'u';
  e = c == 'e';
  o = c == 'o';

  if ( a || i || u || e || o ){
      cout << "vowel" << endl;
  } else {
      cout << "consonant" << endl;
  }
}