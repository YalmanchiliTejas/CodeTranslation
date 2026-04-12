#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define For(i, s, t) for (int i = (s); i <= (t); ++i)

const int maxn = 110;
long long col[maxn][maxn];
int x1[maxn], y1[maxn], x2[maxn], y2[maxn];
bool vis[maxn][maxn];
vector<int> ax, ay;
int n;

void dfs(int x, int y, long long val)
{
    if (x < 0 || x >= maxn || y < 0 || y >= maxn) return;
    if (vis[x][y] || col[x][y] != val) return;
    vis[x][y] = true;
    dfs(x + 1, y, val);
    dfs(x, y + 1, val);
    dfs(x - 1, y, val);
    dfs(x, y - 1, val);
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n && n)
    {
        ax.clear(); ay.clear();
        rep(i, n)
        {
            cin >> x1[i] >> y2[i] >> x2[i] >> y1[i];
            ax.push_back(x1[i]); ax.push_back(x2[i]);
            ay.push_back(y1[i]); ay.push_back(y2[i]);
        }
        sort(ax.begin(), ax.end());
        sort(ay.begin(), ay.end());
        ax.erase(unique(ax.begin(), ax.end()), ax.end());
        ay.erase(unique(ay.begin(), ay.end()), ay.end());
        
        rep(i, n)
        {
            x1[i] = lower_bound(ax.begin(), ax.end(), x1[i]) - ax.begin() + 1;
            x2[i] = lower_bound(ax.begin(), ax.end(), x2[i]) - ax.begin() + 1;
            y1[i] = lower_bound(ay.begin(), ay.end(), y1[i]) - ay.begin() + 1;
            y2[i] = lower_bound(ay.begin(), ay.end(), y2[i]) - ay.begin() + 1;
        }

        memset(col, 0, sizeof(col));
        rep(k, n)
            For(i, x1[k], x2[k] - 1)
                For(j, y1[k], y2[k] - 1)
                    col[i][j] |= 1LL << k;
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        rep(i, maxn)
            rep(j, maxn)
                if (!vis[i][j])
                {
                    ++ans;
                    dfs(i, j, col[i][j]);
                }
        cout << ans << endl;
    }
}