#include <iostream>
using namespace std;

int main() {
  char c;
  cin >> c;
  if("aiueo"s.find_first_of(c) == string::npos) {
    cout << "consonant" << endl;
  } else {
    cout << "vowel" << endl;
  }
  return 0;
}