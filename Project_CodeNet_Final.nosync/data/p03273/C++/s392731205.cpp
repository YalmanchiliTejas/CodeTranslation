#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long inf = numeric_limits<long long>::max();
int main()
{
  int h, w;
  cin >> h >> w;
  vector<bool> row(h, false);
  vector<bool> col(w, false);
  vector<string> grid(h);
  rep(i, h) {
    cin >> grid[i];
  }
  rep(i, h) {
    rep(j, w) {
      if(grid[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }
  rep(i, h) {
    bool render = false;
    if (row[i]) {
      rep(j, w) {
        if (col[j]) {
          render = true;
          cout << grid[i][j];
        }
      }
    }
    if (render) cout << endl;
  } 
  return 0;
}