#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  vector<int> row_blank_count(H,0);
  vector<int> col_blank_count(W,0);
  rep(i,H) {
    rep(j,W) {
      char c;
      cin >> c;
      a.at(i).at(j) = c;
      if ( c == '.' ) {
        row_blank_count.at(i)++;
        col_blank_count.at(j)++;
      }
    }
  }
  rep(i,H) {
    if ( row_blank_count.at(i) == W ) {
      continue;
    }
    rep(j,W) {
      if ( col_blank_count.at(j) == H ) {
        continue;
      }
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
}
