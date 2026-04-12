#include "bits/stdc++.h"
using namespace std;

int main() {
  string C;
  string A;
     cin >> C;
  if(C == "a"||C == "i"|| C == "e"||C == "u"||C == "o"){
    A = "vowel";
  }else{
    A = "consonant";
  }
  cout << A;
  return 0;
}
