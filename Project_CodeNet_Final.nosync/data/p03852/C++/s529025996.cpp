#include<iostream>
using namespace std;

int main(void)
{
  char n;
  cin >> n;
  switch(n)
  {
    case 'a':
    case 'i':
    case 'u':
    case 'e':
    case 'o':
      cout << "vowel" << endl;
      break;
    default:
      cout << "consonant" << endl;
  }
  return 0;
}
