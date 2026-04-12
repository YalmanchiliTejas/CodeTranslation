#include <iostream>
using namespace std;
int main()
{
  char s[5];
  cin >> s;
  if (s[0] != s[1] || s[0] != s[2] || s[1] != s[2]) cout << "Yes" << endl;
  else cout << "No" << endl;
}