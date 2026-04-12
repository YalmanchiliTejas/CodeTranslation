#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <numeric>
#include <ios> // std::left, std::right

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
  int h, w, t, i, j;
  cin >> h >> w;
  bool b;

  vector<vector<char>> a;
  a = vector<vector<char>>(h, vector<char>(w, '0'));

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> a[i][j];
    }
  }

  b = true;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (a[i][j] == '#')
      {
        b = false;
        break;
      }
    }
    if (b)
    {
      for (int j = 0; j < w; j++)
      {
        a[i][j] = '0';
      }
    }
    b = true;
  }

  b = true;

  for (int j = 0; j < w; j++)
  {
    for (int i = 0; i < h; i++)
    {
      if (a[i][j] == '#')
      {
        b = false;
        break;
      }
    }
    if (b)
    {
      for (int i = 0; i < h; i++)
      {
        a[i][j] = '0';
      }
    }
    b = true;
  }

  b = false;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (a[i][j] != '0')
      {
        cout << a[i][j];
        b = true;
      }
    }
    if (b)
      cout << '\n';
    b = false;
  }

  return 0;
}