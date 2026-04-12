#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for (int i = (n); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int g[8][8];
int n, m;

bool used[8] = {};
int ans = 0;

void dfs(int x, int cnt)
{
    if (cnt == n)
    {
        ans++;
        return;
    }

    used[x] = 1;
    rep(i, n)
    {
        if (!used[i] && g[x][i] == 1)
            dfs(i, cnt + 1);
    }
    used[x] = 0;
}

int main()
{
    rep(i, 8) rep(j, 8) g[i][j] = 0;

    cin >> n >> m;

    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b] = g[b][a] = 1;
    }

    dfs(0, 1);

    OP(ans);

    return 0;
}