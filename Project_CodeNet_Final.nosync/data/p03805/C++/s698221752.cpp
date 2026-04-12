#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
typedef long long lint;
const int INF = 1e7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repi(i, k, n) for (int i = (k); i < (int)(n); ++i)
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
int n;
vvi v;
vi visited;
int dfs(int u)
{
    visited[u] = 1;
    int res = 0;
    bool flag = true;
    rep(i, n)
    {
        if (visited[i] == 0)
        {
            flag = false;
        }
    }
    if (flag)
    {
        res++;
    }
    rep(i, v[u].size())
    {
        if (!visited[v[u][i]])
        {
            res += dfs(v[u][i]);
            visited[v[u][i]] = 0;
        }
    }
    return res;
}
int main()
{
    int m;
    cin >> n >> m;
    v.resize(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited.resize(n);
    cout << dfs(0) << endl;
    return 0;
}