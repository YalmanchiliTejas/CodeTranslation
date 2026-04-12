#include <bits/stdc++.h>
using namespace std;
int main()
{
  int h, w;
  cin >> h >> w;
  vector<bool> row(h, false);
  vector<bool> col(w, false);
  vector<vector<char>> vec(h, vector<char>(w));
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> vec.at(i).at(j);
    }
  }

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (vec.at(i).at(j) == '#')
      {
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }
  for (int i = 0; i < h; i++)
  {
    if (row.at(i))
    {
      for (int j = 0; j < w; j++)
      {
        if (col.at(j))
        {
          cout << vec.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}