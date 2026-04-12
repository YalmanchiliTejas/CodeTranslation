#include <iostream>

using namespace std;
int main()
{
  string s;
  cin >> s;
  char c = s[0];
  for (int i = 1; i < 3; i++) {
    if (s[i] != c) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}