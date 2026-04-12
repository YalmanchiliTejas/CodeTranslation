#include <string>
#include <sstream>
#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  if( (s == "a") or (s == "i") or (s == "u") or (s == "e") or(s == "o") ) {
  cout << "vowel" << endl;
  } else{
  cout << "consonant" << endl;
  }
  return 0;
}