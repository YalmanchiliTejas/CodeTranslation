#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

   char s = S.at(0); 
  
  if (s == 'a'||s == 'i'||s == 'u'||s == 'e'|| s == 'o') {
    cout << "vowel" << endl;
  }
    else cout << "consonant" << endl;
}
    