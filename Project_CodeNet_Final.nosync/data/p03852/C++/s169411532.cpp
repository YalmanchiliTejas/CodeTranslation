#include <iostream>
#include <cmath>
using namespace std;

int main() {
  char c;
  cin >> c;
  if(
      c == 'a' ||
      c == 'i' ||
      c == 'u' ||
      c == 'e' ||
      c == 'o')
    cout << "vowel" << std::endl;
  else cout << "consonant" << std::endl;
}