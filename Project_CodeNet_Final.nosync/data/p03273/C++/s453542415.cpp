#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(int i=0;i<(n);++i)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"
const char B = '#', W = '.';


int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int H, W; in(H); in(W);

  char A[H][W];
  rep(i, H) rep(j, W)
    in(A[i][j]);

  vi white_column;
  rep(j, W) {
    bool is_white = true;
    rep(i, H) {
      if (A[i][j] == B)
        is_white = false;
    }
    if (is_white)
      white_column.push_back(j);
  }
  rep(i, H) {
    bool is_white = true;
    rep(j, W) {
      if (A[i][j] == B)
        is_white = false;
    }
    if (is_white)
      continue;
    rep(j, W) {
      if (binary_search(all(white_column), j))
        continue;
      cout << A[i][j];
    }
    cout << "\n";
  }

  return 0;
}
