#include <iostream>
using namespace std;

int main() {
  string v="aiueo";
  char c; cin >> c;
  for(char i:v) {
    if(c==i) {
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
  return 0;
}
