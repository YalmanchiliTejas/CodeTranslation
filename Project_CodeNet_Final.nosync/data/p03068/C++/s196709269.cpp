#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  int a, k;
  string s;
  cin >> a >> s >> k;
  k = k - 1;
  string ans = "";
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == s[k])
    {
      ans += s[k];
    }
    else
      ans += "*";
  }
  cout << ans;
}
