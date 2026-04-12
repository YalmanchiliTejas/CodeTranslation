#include <iostream>
using namespace std;
int main()
{
  int H, W;
  cin >> H >> W;
  char a[H][W];
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
      cin >> a[i][j];
  }
  int check[H][W];
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
      check[i][j] = 0;
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (a[i][j] == '.')
      {
        for (int k = 0; k < H; k++)
        {
          if (a[k][j] == '#')
          {
            check[i][j]++;
            break;
          }
        }
        for (int k = 0; k < W; k++)
        {
          if (a[i][k] == '#')
          {
            check[i][j]++;
            break;
          }
        }
      }
    }
  }
  for (int i = 0; i < H; i++)
  {
    int count = 0;
    for (int j = 0; j < W; j++)
    {
      if (a[i][j] == '#' || (a[i][j] == '.' && 2 == check[i][j]))
      {
        cout << a[i][j];
        count++;
      }
    }
    if (0 < count)
      cout << '\n';
  }
  return 0;
}