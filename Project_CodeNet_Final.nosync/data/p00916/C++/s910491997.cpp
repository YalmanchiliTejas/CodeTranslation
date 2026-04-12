#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

template <typename T>
void coordinateCompression(std::vector<T> &a)
{
    int N = a.size();
    std::vector<T> xs = a;
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i = 0; i < N; i++)
    {
        a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
    }
}

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n, n)
    {
        vector<int> x(2 * n), y(2 * n);
        for (int i = 0; i < n; i++)
        {
            int l, t, r, b;
            cin >> l >> t >> r >> b;
            x[i] = l;
            x[i + n] = r;
            y[i] = t;
            y[i + n] = b;
        }
        coordinateCompression(x);
        // printv(x);
        coordinateCompression(y);
        // printv(y);
        vector<vector<int>> v(400, vector<int>(400, 0));
        for (int i = 0; i < n; i++)
        {
            int l = x[i] + 1, t = y[i] + 1, r = x[i + n] + 1, b = y[i + n] + 1;
            l *= 2;
            t *= 2;
            r *= 2;
            b *= 2;
            for (int j = b; j <= t; j++)
            {
                v[l][j] = 1;
                v[r][j] = 1;
            }
            for (int j = l; j <= r; j++)
            {
                v[j][t] = 1;
                v[j][b] = 1;
            }
        }
        int ret = 0;
        /*
        for (int i = 4*n; i >= 0; i--)
        {
            for (int j = 0; j < 4 * n; j++)
            {
                cout << (v[i][j] ? "*" : " ");
            }
            cout << endl;
        }
        */
        for (int i = 0; i < 400; i++)
        {
            for (int j = 0; j < 400; j++)
            {
                if (v[i][j])
                    continue;
                queue<P> que;
                ret++;
                v[i][j] = 1;
                que.push(P(i, j));
                while (!que.empty())
                {
                    int sx, sy;
                    tie(sx, sy) = que.front();
                    que.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = sx + dx[k], ny = sy + dy[k];
                        if (nx < 0 || 400 <= nx || ny < 0 || 400 <= ny)
                            continue;
                        if (v[nx][ny])
                            continue;
                        v[nx][ny] = 1;
                        que.push(P(nx, ny));
                    }
                }
            }
        }
        cout << ret << endl;
    }
}

