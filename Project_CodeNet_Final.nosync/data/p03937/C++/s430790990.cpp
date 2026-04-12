#include <bits/stdc++.h>
#include <iterator>
#include <tuple>
using namespace std;
using ll = long long;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto &e : s)
    cin >> e;

  bool flag = true;
  for (int i = 0; i < h; ++i)
  {
    for (int j = 0; j < w; ++j)
    {
      if (s[i][j] == '#')
      {
        if ((i > 0 && j > 0) && (s[i - 1][j] == '#' && s[i][j - 1] == '#'))
          flag = false;
        if ((i < h - 1 && j < w - 1) && (s[i + 1][j] == '#' && s[i][j + 1] == '#'))
          flag = false;
      }
    }
  }
  cout << (flag ? "Possible" : "Impossible") << endl;

  return 0;
}