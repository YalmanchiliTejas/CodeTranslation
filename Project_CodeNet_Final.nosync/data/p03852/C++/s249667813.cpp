#include <iostream>
#include <string>
using namespace std;
int main(void) {
  string vowel = "aeiou";
  string c; cin >> c;
  cout << ((int)vowel.find(c) == -1 ? "consonant" : "vowel") << endl;
  return 0;
}
