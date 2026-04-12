#include <bits/stdc++.h>
using namespace std;

int main() {
  string x; // charではだめ
  cin >> x;
  if( x == "a" || x == "e" || x == "i" || x == "o" || x == "u"){ // ""を忘れない
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }
}