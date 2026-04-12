#include <iostream>
using namespace std;

int main() {
  char c;
  cin >> c;
  string out;
  if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') out = "vowel";
  else out = "consonant";
  cout << out << endl;
}
