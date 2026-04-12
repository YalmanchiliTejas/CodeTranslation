#include "bits/stdc++.h"

using namespace std;

using P = pair<int, int>;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

int main()
{
    int h, w;
    while (cin >> h >> w, h || w)
    {
        vector<vector<int>> v(h + 2, vector<int>(w + 2, 1));
        for (int i = 0; i < h; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++)
            {
                if (s[j] == '.')
                    v[i + 1][j + 1] = 0;
            }
        }
        if (v[1][2] || v[2][1])
        {
            cout << "NO" << endl;
            continue;
        }
        int x = 2, y = 1, dir = 0;
        vector<P> path;
        path.push_back(P(1, 1));
        path.push_back(P(x, y));
        while (x != 1 || y != 1)
        {
            int fx = x + dx[dir], fy = y + dy[dir];
            int rx = x + dx[(dir + 1) % 4], ry = y + dy[(dir + 1) % 4];
            int lx = x + dx[(dir + 3) % 4], ly = y + dy[(dir + 3) % 4];
            int bx = x + dx[(dir + 2) % 4], by = y + dy[(dir + 2) % 4];
            // 1. 右側が空いていれば右折
            if (v[rx][ry] == 0)
            {
                dir = (dir + 1) % 4;
                x = rx;
                y = ry;
                path.push_back(P(x, y));
                continue;
            }
            // 2. 正面が空いていれば直進
            if (v[fx][fy] == 0)
            {
                x = fx;
                y = fy;
                path.push_back(P(x, y));
                continue;
            }
            // 3. 左側が空いていれば左折
            if (v[lx][ly] == 0)
            {
                dir = (dir + 3) % 4;
                x = lx;
                y = ly;
                path.push_back(P(x, y));
                continue;
            }
            // 行き止まり
            dir = (dir + 2) % 4;
            x = bx;
            y = by;
            path.push_back(P(x, y));
        }
        int sz = path.size();
        if (path[sz - 1] != P(1, 1))
        {
            cout << "NO" << endl;
            continue;
        }
        int idx11 = sz - 1, idxh1 = -1, idxhw = -1, idx1w = -1;
        for (int i = 1; i < sz; i++)
        {
            if (path[i] == P(h, 1))
                idxh1 = i;
            if (path[i] == P(h, w))
                idxhw = i;
            if (path[i] == P(1, w))
                idx1w = i;
        }
        if (idxh1 == -1 || idxhw == -1 || idx1w == -1)
        {
            cout << "NO" << endl;
            continue;
        }
        auto check = [&](int from, int to) {
            for (int i = from; i <= to; i++)
            {
                int nx = path[i].first, ny = path[i].second;
                if (v[nx][ny])
                    return false;
            }
            for (int i = from; i <= to; i++)
            {
                int nx = path[i].first, ny = path[i].second;
                v[nx][ny] = 1;
            }
            return true;
        };
        // (1, 1) -> (h, 1) -> (h, w) -> (1, w) -> (1, 1) のパスに複数回出現するマスがなければ Yes
        if (!check(1, idxh1) || !check(idxh1 + 1, idxhw) || !check(idxhw + 1, idx1w) || !check(idx1w + 1, idx11))
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}

