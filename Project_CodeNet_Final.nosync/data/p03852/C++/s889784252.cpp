#include <iostream>
#include <string>

using namespace std;

int main(){
  char c;
  string s="aiueo";
  cin >> c;
  cout << ((s.find(c) == string::npos) ? "consonant" : "vowel") << endl;
  return 0;
}