#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1 << 30;
const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};
int n;
int l[55], t[55], r[55], b[55];
int f[210][210];
bool used[210][210];
int limX, limY;

bool contain(int y, int x) {
  return y > 0 && y < limY && x > 0 && x < limX;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  while (cin >> n, n) {
    vector<int> vx, vy;
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> t[i] >> r[i] >> b[i];
      vx.emplace_back(l[i]);
      vx.emplace_back(r[i]);
      vy.emplace_back(b[i]);
      vy.emplace_back(t[i]);
    }
    l[n] = -INF; t[n] = +INF;
    r[n] = +INF; b[n] = -INF;
    vx.emplace_back(-INF);
    vx.emplace_back(+INF);
    vy.emplace_back(-INF);
    vy.emplace_back(+INF);
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());

    map<int, int> zipx, zipy;
    for (int i = 0; i < vx.size(); i++) {
      zipx[vx[i]] = i * 2;
    }
    for (int i = 0; i < vy.size(); i++) {
      zipy[vy[i]] = i * 2;
    }
    fill_n((int*)f, 210*210, 0);
    fill_n((bool*)used, 210*210, false);
    for (int i = 0; i < n+1; i++) {
      for (int x = zipx[l[i]], y = zipy[b[i]]; x <= zipx[r[i]]; x++) f[y][x] = 1;
      for (int x = zipx[l[i]], y = zipy[t[i]]; x <= zipx[r[i]]; x++) f[y][x] = 1;
      for (int x = zipx[l[i]], y = zipy[b[i]]; y <= zipy[t[i]]; y++) f[y][x] = 1;
      for (int x = zipx[r[i]], y = zipy[b[i]]; y <= zipy[t[i]]; y++) f[y][x] = 1;
    }
    limY = zipy[INF]; limX = zipx[INF];

    int ans = 0;
    for (int i = 1; i < limY; i++) {
      for (int j = 1; j < limX; j++) {
        if (f[i][j] == 1 || used[i][j]) continue;
        ans++;
        used[i][j] = true;
        queue<pii> que;
        que.emplace(i, j);
        while (!que.empty()) {
          int y, x;
          tie(y, x) = que.front(); que.pop();
          for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (contain(ny, nx) && !used[ny][nx] && f[ny][nx] == 0) {
              used[ny][nx] = true;
              que.emplace(ny, nx);
            }
          }
        }
      }
    }
    cout << ans << endl;
  }  

  return 0;
}
