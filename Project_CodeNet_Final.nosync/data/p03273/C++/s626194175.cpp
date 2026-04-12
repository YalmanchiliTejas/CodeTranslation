#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl

typedef long long ll;
typedef long double ld;
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w;
  cin >> h >> w;
  char grid[h][w];
  char newgrid[h][w];
  for(int i = 0; i < h; i++)
  {
    for(int j = 0; j < w; j++)
    {
      cin >> grid[i][j];
    }
  }
  for(int i = 0; i < h; i++)
  {
    int j = 0;
    while(j < w)
    {
      if(grid[i][j] == '#')
      {
        break;
      }
      j++;
    }
    if(j == w)
    {
      for(int k = 0; k < w; k++)
      {
        newgrid[i][k] = 'x';
      }
    }
  }
  for(int i = 0; i < w; i++)
  {
    int j = 0;
    while(j < h)
    {
      if(grid[j][i] == '#')
      {
        break;
      }
      j++;
    }
    if(j == h)
    {
      for(int k = 0; k < h; k++)
      {
        newgrid[k][i] = 'x';
      }
    }
  }
  for(int i = 0; i < h; i++)
  {
    bool flag = 0;
    for(int j = 0; j < w; j++)
    {
      if(newgrid[i][j] != 'x')
      {
        flag = 1;
        cout << grid[i][j];
      }
    }
    if(flag)
    {
      cout << endl;
    }
  }

  return 0;
}
