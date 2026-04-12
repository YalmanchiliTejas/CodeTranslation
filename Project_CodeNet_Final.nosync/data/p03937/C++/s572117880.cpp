#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main() {

    int h, w; cin >> h >> w;

    vector<string> a(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> d(h, vector<int>(w, -1));

    d[0][0] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        for (int i = 0; i < 2; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
            if (d[nx][ny] != -1) continue;
            if (a[nx][ny] == '.') continue;

            d[nx][ny] = d[p.first][p.second] + 1;
            q.push(make_pair(nx, ny));
        }
    }


    int cnt[100] = {};
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#') {
                if (d[i][j] == -1) {
                    puts("Impossible");
                    return 0;
                }
                
                if (cnt[d[i][j]] == 1) {
                    puts("Impossible");
                    return 0;
                } else {
                    cnt[d[i][j]] = 1;
                }
            }
        }
    }

    if (d[h - 1][w - 1] == -1) {
        puts("Impossible");
    } else {
        puts("Possible");
    }
}