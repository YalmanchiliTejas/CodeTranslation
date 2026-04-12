#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
const ll LINF = 1e18;

int main()
{
  int H, W; cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  REP(h, H) REP(w, W) cin >> A[h][w];

  vector<vector<bool>> visit(H, vector<bool>(W, false));
  visit[0][0] = visit[H-1][W-1] = true;

  int h = 0, w = 0;
  while (!(h == H-1 && w == W-1)) {
    if (h+1 < H && A[h+1][w] == '#') {
      h++;
      visit[h][w] = true;
    } else if (w+1 < W && A[h][w+1] == '#') {
      w++;
      visit[h][w] = true;
    } else {
      cout << "Impossible" << endl;
      return 0;
    }
  }

  REP(h, H) REP(w, W) {
    if (A[h][w] == '#' && !visit[h][w]) {
      cout << "Impossible" << endl;
      return 0;
    }
  }

  cout << "Possible" << endl;
}