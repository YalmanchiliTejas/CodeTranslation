#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  vector<int> cntH(W);
  vector<int> cntW(H);

  for (int i = 0; i < H; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (a[i][j] == '#')
      {
        cntH[j]++;
        cntW[i]++;
      }
    }
  }

  for (int i = 0; i < H; i++)
  {
    if (cntW[i] == 0)
    {
      continue;
    }

    for (int j = 0; j < W; j++)
    {
      if (cntH[j] == 0)
      {
        continue;
      }

      cout << a[i][j];
    }
    cout << endl;
  }
}
