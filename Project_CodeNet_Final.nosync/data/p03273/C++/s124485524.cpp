#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> board(h);
  rep(i, h)
  {
    cin >> board.at(i);
  }

  vector<bool> row(h, false);
  vector<bool> col(w, false);

  rep(i, h)
  {
    rep(j, w)
    {
      if(board.at(i).at(j) == '#')
      {
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }

  rep(i, h)
  {
    if(row.at(i))
    {
      rep(j, w)
      {
        if(col.at(j))
        {
          cout << board.at(i).at(j);
        }
      }
      cout << endl;
    }
  }

}
