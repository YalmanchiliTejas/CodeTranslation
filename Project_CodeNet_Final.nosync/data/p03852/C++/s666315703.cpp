#include <bits/stdc++.h>
using namespace std;

int main(){
  string c;
  cin >> c;
  if (c[0] == 'a' ||
      c[0] == 'i' ||
      c[0] == 'u' ||
      c[0] == 'e' ||
      c[0] == 'o')
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
  
  return 0;
  
}