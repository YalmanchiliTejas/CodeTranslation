#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<map<char, int>> table;

  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;

    map<char, int> m;
    for (int j = 0; j < s.length(); j++)
    {
      if (m.count(s[j]))
      {
        m[s[j]]++;
      }
      else
      {
        m[s[j]] = 1;
      }
    }

    table.push_back(m);
  }

  map<char, int> common;
  map<char, int> fir = table[0];
  for (map<char, int>::iterator it = fir.begin(); it != fir.end(); it++)
  {
    char ch = it->first;
    int count = it->second;
    for (int i = 1; i < table.size(); i++)
    {
      count = std::min(count, table[i][ch]);
    }

    common[ch] = count;
  }

  string res = "";

  for (auto it = common.begin(); it != common.end(); it++)
  {
    for (int i = 0; i < it->second; i++)
    {
      res += it->first;
    }
  }

  cout << res << endl;
}