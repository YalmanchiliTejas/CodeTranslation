#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      cin >> a.at(i).at(j);
    }
  }

  // 表示すべき行と列をチェック
  vector<bool> h(H, false);
  vector<bool> w(W, false);

  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      if (a.at(i).at(j) == '#')
      {
        h.at(i) = true;
        w.at(j) = true;
      }
    }
  }

  // 表示
  for (int i = 0; i < H; ++i)
  {
    if (h.at(i))
    {
      for (int j = 0; j < W; ++j)
      {
        if (w.at(j))
        {
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }

  return 0;
}