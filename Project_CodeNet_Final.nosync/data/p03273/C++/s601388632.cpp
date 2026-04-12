#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define Cout(s) cout << s << endl;
#define CoutV(vec)     \
    for (auto v : vec) \
        Cout(v);
#define CoutVV(vecvec)      \
    for (auto vec : vecvec) \
        CoutV(vec);

using ll = long long;
using P = pair<int, int>;

const ll INF = 1ll << 60;
ll MOD = 1e9 + 7;
//int t[10010];

int main()
{

    int h, w;
    cin >> h >> w;
    vector<vector<char>> m(h, vector<char>(w));
    REP(i, h)
    {
        REP(j, w)
        {

            cin >> m[i][j];
        }
    }
    vector<bool> ziph(h, false);
    vector<bool> zipw(w, false);
    REP(y, h)
    {
        bool ok = true;
        REP(x, w)
        {
            if (m[y][x] == '#')
            {
                ok = false;
            }
        }
        if (ok)
        {
            ziph[y] = true;
        }
    }

       REP(x, w)
    {
        bool ok = true;
        REP(y, h)
        {
            if (m[y][x] == '#')
            {
                ok = false;
            }
        }
        if (ok)
        {
            zipw[x] = true;
        }
    }

    REP(y, h)
    {
        REP(x, w)
        {
            if (!zipw[x] && !ziph[y])
            {
                cout << m[y][x];
            }
            if (x == w - 1 && !ziph[y])
                cout << endl;
        }
    }

    return 0;
}