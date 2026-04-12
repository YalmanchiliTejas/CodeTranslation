#include <iostream>
#include <string>
#include <vector>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int H, W;
  cin >> H >> W;

  vector<vector<char>> a(H);
  std::set<int> row;
  std::set<int> col;
  rep(i, H)
  {
    a[i].resize(W);
    bool white = true;
    rep(j, W)
    {
      cin >> a[i][j];
      if (a[i][j] != '.')
      {
        white = false;
      }
    }
    if (white)
      row.insert(i);
  }

  rep(j, W)
  {
    bool white = true;
    rep(i, H)
    {
      if (a[i][j] != '.')
      {
        white = false;
      }
    }

    if (white)
      col.insert(j);
  }

  rep(i, H)
  {
    if (row.find(i) != row.end())
    {
      continue;
    }
    rep(j, W)
    {
      if (col.find(j) != col.end())
      {
        continue;
      }
      cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}
