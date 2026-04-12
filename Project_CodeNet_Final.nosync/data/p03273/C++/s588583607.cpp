#include <bits/stdc++.h>
#include <iterator>
#include <tuple>
using namespace std;
using ll = long long;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> a;
  for (int i = 0; i < h; ++i)
  {
    string s;
    cin >> s;
    bool c = true;
    for (int j = 0; j < w; ++j)
    {
      if (s[j] == '#')
        c = false;
    }
    if (!c)
      a.push_back(s);
  }
  vector<int> check;
  for (int i = 0; i < w; ++i)
  {
    bool c = true;
    for (int j = 0; j < a.size(); ++j)
    {
      if (a[j][i] == '#')
        c = false;
    }
    if (!c)
      check.push_back(i);
  }
  for (int i = 0; i < a.size(); ++i)
  {
    for (int j = 0; j < w; ++j)
    {
      bool c = true;
      for (int k = 0; k < check.size(); ++k)
      {
        if (check[k] == j)
          c = false;
      }
      if (!c)
        cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}