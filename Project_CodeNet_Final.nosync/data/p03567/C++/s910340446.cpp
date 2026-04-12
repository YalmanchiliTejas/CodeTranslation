
#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string s;
  
  cin >> s;
  
  bool ok = false;
  
  for ( int i = 0 ; i < s.length() - 1 ; i++ ) {
    if ( s[i] == 'A' and s[i+1] == 'C' ) ok = true;
  }
  
  if ( ok ) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
