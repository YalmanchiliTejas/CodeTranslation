#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

int n, m;
int gr[10][10] = {};
int use[10] = {};
ll ans = 0;

int dfs(int depth, int p)
{
    if (depth == n)
    {
        ans++;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (use[i] == 0 && gr[p][i] == 1)
            {
                use[i] = 1;
                dfs(depth + 1, i);
                use[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        gr[a][b] = gr[b][a] = 1;
    }
    use[1] = 1;
    dfs(1, 1);
    cout << ans << endl;
}
