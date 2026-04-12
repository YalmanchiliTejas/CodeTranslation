#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<vector<char> > table(H, vector<char>(W));

  for (int h = 0; h < H; ++h)
  {
    for (int w = 0; w < W; ++w)
    {
      cin >> table.at(h).at(w);
    }
  }

  vector<bool> row(H, false);
  vector<bool> col(W, false);

  for (int h = 0; h < H; ++h)
  {
    for (int w = 0; w < W; ++w)
    {
      if (table.at(h).at(w) == '#')
      {
        row.at(h) = true;
        col.at(w) = true;
      }
    }
  }
  for (int h = 0; h < H; ++h)
  {
    if (row.at(h))
    {
      for (int w = 0; w < W; ++w)
      {
        if (col.at(w))
        {
          cout << table.at(h).at(w);
        }
      }
      cout << endl;
    }
  }
}