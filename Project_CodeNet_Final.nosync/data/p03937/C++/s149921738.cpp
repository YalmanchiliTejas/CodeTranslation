#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll
#define all(v) v.begin(), v.end()
#define reps(__i, a, b) for (int __i = a; i < b; i++)
#define rep(__i, n) reps(__i, 0, n)

const ll INF = (1ll << 60);
const ll MOD = (ll)1e9 + 7;

int h, w;
char arr[10][10] = {};

bool dfs(int y, int x)
{
    if (y == h && x == w)
    {
        // cout << "aaa" << endl;
        return true;
    }
    else
    {
        bool f = false;
        if (x + 1 <= w && arr[y][x + 1] == '#')
            f |= dfs(y, x + 1);
        if (y + 1 <= h && arr[y + 1][x] == '#')
            f |= dfs(y + 1, x);
        return f;
    }
}

signed main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < w; j++)
            arr[i + 1][j + 1] = tmp[j];
    }
    bool f = true;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (i - 1 >= 1 && j + 1 <= w)
            {
                if (arr[i][j] == '#' && arr[i - 1][j + 1] == '#')
                    f = false;
            }
        }
    }
    // if (dfs(1, 1) && f)
    if (f)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
}