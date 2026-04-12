#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  string t = "aeiou";

  cin >> s;

  for (int i = 0; i < t.size(); i++) {
    if (s[0] == t[i]) {
      cout << "vowel" << endl;
      return 0;
    }
  }

  cout << "consonant" << endl;

  return 0;
}
