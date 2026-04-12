#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<string> S(n);
  vector<vector<int>> alpha(n, vector<int>(26));
  vector<int> ans(26, 1000000);
  for (int i = 0; i < n; i++)
  {
    cin >> S.at(i);
    for (int j = 0; j < S.at(i).size(); j++)
    {
      alpha.at(i).at(S.at(i).at(j) - 'a')++;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < alpha.at(i).size(); j++)
    {
      ans.at(j) = min(ans.at(j), alpha.at(i).at(j));
    }
  }

  for (int i = 0; i < ans.size(); i++)
  {
    if (ans.at(i) != 0)
    {
      for (int j = 0; j < ans.at(i); j++)
      {
        cout << (char)('a' + i);
      }
    }
  }
  cout << endl;
}
