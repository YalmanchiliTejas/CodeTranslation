#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<vector<int>> alph(n, vector<int>(26, 0));

  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); j++) alph[i][s[j] - 'a']++;
  }

  string ans = "";

  for (int i = 0; i < 26; i++)
  {
    int max_num = alph[0][i];
    for (int j = 1; j < n; j++) max_num = min(max_num, alph[j][i]);
    for (int k = 0; k < max_num; k++) ans += i + 'a';
  }

  cout << ans << endl;
  return 0;
}