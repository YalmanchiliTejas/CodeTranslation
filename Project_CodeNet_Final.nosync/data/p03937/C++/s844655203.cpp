#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

void solve(void)
{
    int xx[] = {0, 1};
    int yy[] = {1, 0};
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    vector<vector<int>> f(h, vector<int>(w, -1));
    int sy = 0, sx = 0;
    f[sy][sx] = 0;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    while (!q.empty())
    {
        auto s = q.front();
        q.pop();
        int y = s.first, x = s.second;
        rep(i, 2)
        {
            int ny = y + yy[i], nx = x + xx[i];
            if (ny >= h || nx >= w)
                continue;
            if (a[ny][nx] == '#' && f[ny][nx] == -1)
                f[ny][nx] = f[y][x] + 1, q.push({ny, nx});
        }
    }
    map<int, int> mp;
    rep(i, h) rep(j, w) if (a[i][j] == '#') mp[f[i][j]]++;
    rep(i, h) rep(j, w)
    {
        if (f[i][j] == -1 && a[i][j] == '#')
        {
            cout << "Impossible" << endl;
            return;
        }
    }
    bool flag = true;
    for (auto i : mp)
    {
        if (i.first == -1)
            continue;
        if (i.second > 1)
            flag = false;
    }
    if (flag)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
}
int main(void)
{
    solve();
}