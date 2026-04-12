#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for (int i = x, i##_len = (n); i < i##_len; ++i)
#define ALL(n) begin(n), end(n)

int main()
{
  int H, W;
  cin >> H >> W;
  vector<vector<char>> v(H, vector<char>(W));
  rep(i, H) rep(j, W) cin >> v[i][j];

  //横を確認
  rep(i, H)
  {
    bool white = true;
    rep(j, W)
    {
      if (v[i][j] == '#')
        white = false;
    }
    if (white)
      rep(j, W) v[i][j] = 'x';
  }

  //縦を確認
  rep(j, W)
  {
    bool white = true;
    rep(i, H)
    {
      if (v[i][j] == '#')
        white = false;
    }
    if (white)
      rep(i, H) v[i][j] = 'x';
  }

  rep(i, H)
  {
    bool isLine = false;
    rep(j, W) if (v[i][j] != 'x')
    {
      cout << v[i][j];
      isLine = true;
    }
    if (isLine)
      cout << endl;
  }
}