#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 10, mod = 1e9 + 7;

int n, m;
LL res;
bool g[N][N];
bool st[N];

void dfs(int u, int c)
{
    if(c == n && !st[u])
    {
        res++;
        return;
    }

    st[u] = true;
    for(int i = 1; i <= n; i++)
        if(g[u][i] && !st[i])
            dfs(i, c + 1);
    st[u] = false;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }

    dfs(1, 1);

    cout << res << endl;
    return 0;
}
