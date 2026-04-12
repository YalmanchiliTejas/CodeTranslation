#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string s[60] = {};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  string ans;
  for (char c = 'a'; c <= 'z'; c++)
  {
    int small = 100;

    for (int i = 0; i < n; i++)
    {
      int cnt = 0;
      for (int j = 0; j < s[i].length(); j++)
      {
        if (s[i][j] == c)cnt++;

      }
      small = min(small, cnt);
    }
    for (int i = 0; i < small; i++)
    {
      ans += c;
    }
  }
  cout << ans << endl;
  return 0;
}