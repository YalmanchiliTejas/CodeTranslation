#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)

int main()
{

  int H, W;
  cin >> H >> W;

  string board[110];

  bool goodx[110], goody[110];
  rep(i, 110)
  {
    goodx[i] = false;
    goody[i] = false;
  }

  rep(i, H)
  {
    cin >> board[i];
  }

  rep(i, H)
  {
    rep(j, W)
    {
      if (board[i][j] == '#')
      {
        goodx[i] = true;
        goody[j] = true;
      }
    }
  }

  rep(i, H)
  {
    if (goodx[i])
    {
      rep(j, W)
      {
        if (goody[j])
        {
          cout << board[i][j];
        }
      }
      cout << endl;
    }
  }
}