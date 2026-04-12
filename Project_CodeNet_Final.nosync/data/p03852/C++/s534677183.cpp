#include <bits/stdc++.h>
using namespace std;
int main(void){
  string A;
  cin >> A;
  if(A == "a" || A == "i" || A == "u" || A == "e" || A == "o" ){
    cout << "vowel";
  } else {
    cout << "consonant";
  }
}