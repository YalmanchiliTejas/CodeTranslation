#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> grid(H);
  rep(i, H)
  {
    cin >> grid[i];
  }
  vector<bool> deleteH(H, false), deleteW(W, false);
  rep(h, H)
  {
    bool is_all_white = true;
    rep(w, W)
    {
      if (grid[h][w] == '#')
        is_all_white = false;
    }
    if (is_all_white)
      deleteH[h] = true;
  }
  rep(w, W)
  {
    bool is_all_white = true;
    rep(h, H)
    {
      if (grid[h][w] == '#')
        is_all_white = false;
    }
    if (is_all_white)
      deleteW[w] = true;
  }

  rep(h, H)
  {
    if (deleteH[h])
      continue;
    rep(w, W)
    {
      if (deleteW[w])
        continue;
      cout << grid[h][w];
    }
    cout << endl;
  }
  return 0;
}