#include <iostream>

using namespace std;

int main() {
  constexpr char v[] = {'a', 'e', 'i', 'o', 'u'};

  char c;
  cin >> c;
  for (char e : v) {
    if (c == e) {
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;

  return 0;
}
