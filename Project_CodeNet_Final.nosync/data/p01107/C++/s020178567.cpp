#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int N, M;
int cur = 1;
int ans = 0;
int sx, sy;
vector<string> c;

void checkandFill() {
  for (P p : vector<P>{{0, M - 1}, {N - 1, M - 1}, {N - 1, 0}}) {
    if (P{sx, sy} != p) continue;
    ++ans;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (c[i][j] == '!') c[i][j] = '#';
      }
    }
  }
}

bool nextPosition() {
  for (int i = -1; i < 3; ++i) {
    int tx = sx + dx[(i + cur + 4) % 4];
    int ty = sy + dy[(i + cur + 4) % 4];
    if (0 <= tx && tx < N && 0 <= ty && ty < M) {
      for (int j = 0; j < 2; ++j) {
        if (c[tx][ty] == ".!"[j]) {
          if (sx != 0 || sy != 0) c[sx][sy] = "!#"[j];
          sx = tx;
          sy = ty;
          cur = (i + cur + 4) % 4;
          return true;
        }
      }
    }
    if (i == 2) return false;
  }
}

bool solve() {
  ans = 0;
  cur = 0;
  sx = 0;
  sy = 0;
  while (true) {
    checkandFill();
    if (not nextPosition()) return false;
    if (sx == 0 && sy == 0) return (ans == 3);
  }
}

int main() {
  while (cin >> N >> M, N) {
    c = vector<string>(N);
    for (int i = 0; i < N; ++i) cin >> c[i];
    cout << ( solve() ? "YES" : "NO" ) << endl;
  }
}

