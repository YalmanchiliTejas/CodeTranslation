#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  char input;
  cin >> input;
  switch (input) {
    case 'a':
    case 'i':
    case 'u':
    case 'e':
    case 'o':
      cout << "vowel";
      break;
    default:
      cout << "consonant";
      break;
  }
  return 0;
}
