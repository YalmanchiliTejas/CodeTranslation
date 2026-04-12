#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int H, W;

vi judgetate(100), judgeyoko(100);
vector<vector<char>> masu(100, vector<char>(100));

int main()
{
  int H, W;
  cin >> H >> W;

  rep(i, H)
  {
    rep(j, W)
    {
      cin >> masu[i][j];
    }
  }

  rep(i, W)
  {
    judgetate[i] = 0;
    rep(j, H)
    {
      if (masu[j][i] == '#')
      {
        judgetate[i] = 1;
      }
    }
  }

  rep(i, H)
  {
    judgeyoko[i] = 0;
    rep(j, W)
    {
      if (masu[i][j] == '#')
      {
        judgeyoko[i] = 1;
      }
    }
  }

  rep(i, H)
  {
    rep(j, W)
    {
      if (judgetate[j] == 1 && judgeyoko[i] == 1)
        cout << masu[i][j];
    }
    if (judgeyoko[i] == 1)
      cout << endl;
  }
  return 0;
}
