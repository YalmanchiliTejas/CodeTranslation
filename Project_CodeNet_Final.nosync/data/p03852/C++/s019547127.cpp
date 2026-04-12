#include <bits/stdc++.h>

using namespace std;

int main() {
  char c;
  cin >> c;
  char s[6] = "aiueo";
  bool flag = 0;

  for( int i = 0; i < 5; i++ ) {
    if( c == s[i] ) {
      cout << "vowel" << endl;
      flag = 1;
      break;
    }
  }
  if( flag == 0 )
    cout << "consonant" << endl;
  return 0;
}