#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<vector<char>> vv(h, vector<char>(w));
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> vv.at(i).at(j);

  for (int i = 0; i < h; i++)
  {
    bool is_white = true;
    for (int j = 0; j < w; j++)
    {
      if (vv.at(i).at(j) == '#')
      {
        is_white = false;
        break;
      }
    }
    if (is_white)
      for (int j = 0; j < w; j++)
        vv.at(i).at(j) = 'N';
  }

  for (int i = 0; i < w; i++)
  {
    bool is_white = true;
    for (int j = 0; j < h; j++)
    {
      if (vv.at(j).at(i) == '#')
      {
        is_white = false;
        break;
      }
    }
    if (is_white)
      for (int j = 0; j < h; j++)
        vv.at(j).at(i) = 'N';
  }

  for (int i = 0; i < h; i++)
  {
    bool exists = false;
    for (int j = 0; j < w; j++)
    {
      if (vv.at(i).at(j) != 'N')
      {
        cout << vv.at(i).at(j);
        exists = true;
      }
    }
    if (exists)
      cout << endl;
  }
  return 0;
}
