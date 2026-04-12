#include <iostream>
using namespace std;

int main() {
  char C;
  cin >> C;
  if((C == 'a')||(C == 'i')||(C == 'u')||(C == 'e')||(C == 'o'))
    cout << "vowel\n";
  else
    cout << "consonant\n";
  return 0;
}
