#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;
#define SZ(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
const int maxint = -1u>>1;
const int maxn = 50 + 2;
const int maxm = 1000 + 10;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int r, c, m;
char s[maxn][maxn];
int open[maxn][maxn], inst[maxn][maxn], cl[maxn][maxn];
pair<int, int> rec[maxm];
vector<pair<int, int> > p;
vector<int> tm[maxn][maxn];
bool used[maxn][maxn];

bool dfs(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return true;
    if (used[x1][y1]) return false;
    used[x1][y1] = true;
    p.push_back(make_pair(x1, y1));
    for (int i = 0; i < 4; ++i) {
        int tx = x1 + dx[i], ty = y1 + dy[i];
        if (tx < 0 || ty < 0 || tx >= r || ty >= c || s[tx][ty] != '.') continue;
        if (dfs(tx, ty, x2, y2)) return true;
    }
    p.pop_back();
    return false;
}
int main() {
    while (scanf("%d%d%d", &r, &c, &m) == 3) {
        for (int i = 0; i < r; ++i) {
            scanf("%s", s[i]);
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                tm[i][j].clear();
                scanf("%d", &inst[i][j]);
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                scanf("%d", &open[i][j]);
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                scanf("%d", &cl[i][j]);
            }
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &rec[i].first, &rec[i].second);
        }
        int now = 0;
        for (int i = 1; i < m; ++i) {
            memset(used, 0, sizeof(used));
            p.clear();
            dfs(rec[i - 1].first, rec[i - 1].second, rec[i].first, rec[i].second);
            for (int j = 0; j < (int) p.size(); ++j) {
                tm[p[j].first][p[j].second].push_back(now);
                ++now;
            }
        }
        tm[rec[m - 1].first][rec[m - 1].second].push_back(now);
        int ans = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (tm[i][j].size() == 0) continue;
                //printf("%d %d: ", i, j);for (int k = 0; k < (int)tm[i][j].size(); ++k) printf("%d ", tm[i][j][k]); printf("\n");
                ans += open[i][j] + cl[i][j] + inst[i][j] * (tm[i][j].back() - tm[i][j].front());
                for (int k = 1; k < (int)tm[i][j].size(); ++k) {
                    if ((tm[i][j][k] - tm[i][j][k - 1]) * inst[i][j] > open[i][j] + cl[i][j]) {
                        ans -= (tm[i][j][k] - tm[i][j][k - 1]) * inst[i][j] - open[i][j] - cl[i][j];
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}