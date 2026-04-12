#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;

  deque<string> rows;

  set<int> colIdxSet;

  for (int i = 0; i < h; i++)
  {
    string s;
    cin >> s;
    if (s.find('#') != string::npos)
    {
      for (int j = 0; j < s.size(); j++)
      {
        if (s[j] == '#')
        {
          colIdxSet.insert(j);
        }
      }
      rows.push_back(s);
    }
  }

  for (int i = 0; i < rows.size(); i++)
  {
    string row = rows[i];

    for (int j = 0; j < row.size(); j++)
    {
      if (colIdxSet.find(j) != colIdxSet.end())
      {
        cout << row[j];
      }
    }
    cout << endl;
  }

  return 0;
}
