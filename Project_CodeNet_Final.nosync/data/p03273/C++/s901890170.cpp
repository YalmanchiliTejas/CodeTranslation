#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;

  vector<bool> col(H,false), row(W,false);
  vector< vector<char> > squares(H, vector<char>(W));
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      cin >> squares[i][j];
      if (i == 0)
      {
        if (squares[i][j] == '.') row[j] = true;
      }
      else
      {
        if (squares[i][j] == '#') row[j] = false;
      }

      if (j == 0)
      {
        if (squares[i][j] == '.') col[i] = true;
      }
      else
      {
        if (squares[i][j] == '#') col[i] = false;
      }
    }
  }

  for (int i = 0; i < H; ++i)
  {
    if (col[i] == true) continue;
    for (int j = 0; j < W; ++j)
    {
      if (row[j] == true) continue;
      cout << squares[i][j];
    }
    cout << endl;
  }
}