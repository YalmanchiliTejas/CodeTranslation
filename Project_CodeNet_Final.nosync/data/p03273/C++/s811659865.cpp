#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int h, w;
  vector<vector<char>> a(100, vector<char>(100));
  vector<bool> a_row(100, true), a_col(100, true);

  cin >> h >> w;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> a[i][j];
      if (a[i][j] == '#')
      {
        a_row[i] = false;
        a_col[j] = false;
      }
    }
  }
  for (int i = 0; i < h; i++)
  {
    if (a_row[i])
      continue;
    for (int j = 0; j < w; j++)
    {
      if (a_col[j])
        continue;
      cout << a[i][j];
    }
    cout << endl;
  }
}