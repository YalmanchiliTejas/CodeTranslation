#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;
#define pow10(n) int(1e##n + n)
char g[101][101];
void solve()
{
    int H, W;
    cin >> H >> W;
    vector<int> row, col;
    REP0 (i, H)
    {
        bool isskip = true;
        REP0 (j, W)
        {
            cin >> g[i][j];
            if (g[i][j] == '#')
                isskip = false;
        }
        if (isskip)
            continue;

        row.push_back(i);
    }

    REP0 (j, W)
    {
        bool isskip = true;
        REP0 (i, H)
        {
            if (g[i][j] == '#')
                isskip = false;
        }
        if (isskip)
            continue;

        col.push_back(j);
    }

    for (auto i : row)
    {
        for (auto j : col)
        {
            cout << g[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
