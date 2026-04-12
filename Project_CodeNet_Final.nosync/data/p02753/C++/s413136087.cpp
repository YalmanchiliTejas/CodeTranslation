#include <string>
#include <iostream>

using namespace std;

int main()
{
  string s;
  cin >> s;
  char c = s[0];
  for (int i = 1; i < s.size(); ++i)
  {
    if (c != s[i])
    {
      cout << "Yes" << endl;
      return 0;
    }
    c = s[i];
  }
  cout << "No" << endl;
  return 0;
}