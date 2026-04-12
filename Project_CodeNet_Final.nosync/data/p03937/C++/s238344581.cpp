#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H,W; cin >> H >> W;
  vector<string> A(H);
  rep(i, H) cin >> A[i];

  int h = 0, w = 0;
  while(h >= 0 && h < H && w >= 0 && w < W) {
    A[h][w] = '.';

    int cnt = 0;
    int nnh = h;
    int nnw = w;
    rep(i, 4) {
      int nh = h + dy[i];
      int nw = w + dx[i];

      if(nh >= 0 && nh < H && nw >= 0 && nw < W && A[nh][nw] == '#') {
        if(i == 0 || i == 1) {
          if(cnt) {
            cout << "Impossible" << endl;
            return 0;
          } else {
            nnh = nh;
            nnw = nw;
          }
          ++cnt;
        } else {
          cout << "Impossible" << endl;
          return 0;
        }
      }
    }
    h = nnh;
    w = nnw;
    if(cnt == 0) break;
  }

  cout << "Possible" << endl;
  return 0;
}
