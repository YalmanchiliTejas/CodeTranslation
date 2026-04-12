#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

int g[8][8];
int n;

int dfs(int v, vector<int> visited)
{
    if (accumulate(ALL(visited), 0) == n)
        return 1;

    int sum = 0;

    rep(i, n)
    {
        if (!g[v][i] || visited[i])
            continue;

        visited[i] = 1;
        sum += dfs(i, visited);
        visited[i] = 0;
    }

    return sum;
}

int main()
{

    int m;
    cin >> n >> m;
    rep(i, n) rep(j, n) g[i][j] = 0;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        g[a - 1][b - 1] = g[b - 1][a - 1] = 1;
    }

    vector<int> visited(8);
    rep(i, n) visited[i] = 0;

    visited[0] = 1;

    OP(dfs(0, visited));

    return 0;
}