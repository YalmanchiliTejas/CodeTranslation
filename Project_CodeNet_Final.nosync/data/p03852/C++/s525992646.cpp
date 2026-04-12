#include <bits/stdc++.h>
using namespace std;

int main(void){
  char c;

  //is vowel?
  cin >> c;
  switch(c){
  case 'a':  case 'e':  case 'i':  case 'o':  case 'u':
    cout << "vowel" << endl;
    break;
  default:
    cout << "consonant" << endl;
    break;
  }

  return 0;
}