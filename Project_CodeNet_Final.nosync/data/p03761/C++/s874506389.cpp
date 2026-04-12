#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  cin >> n;
  string S[n];
  for (int i = 0; i < n; i++)
    cin >> S[i];
  int al[26];
  for (int i = 0; i < 26; i++)
    al[i] = 51;
  for (int i = 0; i < n; i++)
  {
    int al_tmp[26] = {};
    for (int j = 0; j < S[i].length(); j++)
    {
      char c = S[i][j];
      al_tmp[c - 'a']++;
    }
    for (int i = 0; i < 26; i++)
      al[i] = min(al[i], al_tmp[i]);
  }
  string ans = "";
  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < al[i]; j++)
      ans += (char)(i + 'a');
  }
  sort(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}