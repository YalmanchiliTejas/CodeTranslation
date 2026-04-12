#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define repi(i, a, b) for (int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ull << (b))

using namespace std;
using i32 = long long;
using u32 = unsigned long long;
using i64 = long long;
using u64 = unsigned long long;
using f64 = double;
using vi32 = vector<i32>;
using vu32 = vector<u32>;
using vi64 = vector<i64>;
using vu64 = vector<u64>;
using vf64 = vector<f64>;
using vstr = vector<string>;
using vvi32 = vector<vi32>;
using vvu32 = vector<vu32>;
using vvi64 = vector<vi64>;
using vvu64 = vector<vu64>;
using vvf64 = vector<vf64>;

template<typename T, typename S> void amax(T &x, S y) { if (x < y) x = y; }
template<typename T, typename S> void amin(T &x, S y) { if (y < x) x = y; }

int H, W;
vstr a;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool bfs() {
  queue<pair<int, int>> q;  // (h, w)
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    auto p = q.front(); q.pop();
    int y = p.first, x = p.second;
    a[y][x] = '.';
    int cnt = 0;
    rep(i, 4) {
      int yy = y + dy[i], xx = x + dx[i];
      if (yy < 0 || yy >= H || xx < 0 || xx >= W) continue;
      if (a[yy][xx] == '#') {
        if (cnt > 0) return false;
        if (yy < y || xx < x) return false;
        cnt++;
        q.push(make_pair(yy, xx));
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
  cin >> H >> W;
  a = vstr(H);
  rep(i, H) cin >> a[i];
  if (bfs()) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}