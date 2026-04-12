#include <iostream>
using namespace std;
int main()
{
  int a = 0, b = 0;
  char s[10];
  cin >> s;
  s[0] == 'A' ? a++ : b++;
  s[1] == 'A' ? a++ : b++;
  s[2] == 'A' ? a++ : b++;
  if ( a > 0 && b > 0 ) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}