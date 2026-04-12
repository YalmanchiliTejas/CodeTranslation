#include <iostream>
#include <vector>
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
    for (int j = 0; j < (int)s.size(); j++)
    {
      alph[i][s[j] - 'a']++;
    }
  }

  string ans = "";

  for (int i = 0; i < 26; i++)
  {
    bool doing = true;
    while (doing)
    {
      for (int j = 0; j < n; j++)
      {
        if (alph[j][i] == 0) 
        {
          doing = false;
          break;
        }
        else alph[j][i]--;
      }
      if (doing) ans += i + 'a';
    }
  }

  cout << ans << endl;
  return 0;
}