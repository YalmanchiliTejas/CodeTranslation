#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  char vow[5]={'a','e','i','o','u'};
  for ( int i=0; i<5; i++ ) {
    if ( c==vow[i] ) {
      cout << "vowel";
      return 0;
    }
  }
  cout << "consonant";
  return 0;
}
  