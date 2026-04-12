#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  string judge;
  
  cin >> c;
  switch(c) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    judge = "vowel";
    break;
  default:
    judge = "consonant";
    break;
  }

  cout << judge << endl;
  return 0;
}
