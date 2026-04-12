#include <iostream>
#include <string>
using namespace std;

int main(){
  char c;
  cin >> c;
  string vowel = "aeiou";
  if (vowel.find(c) == string::npos) {
    cout << "consonant" << endl;
  } else {
    cout << "vowel" << endl;
  }
  return 0;
}
