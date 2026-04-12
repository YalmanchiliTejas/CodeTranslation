#include <iostream>

using namespace std;

int main()
{
  char a;

  cin >> a;
  if( a == 'a' || a == 'i' || a == 'e' || a == 'o' || a == 'u')
    cout << "vowel";
  else
    cout << "consonant";
    return 0;
}
