#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD (1000000007)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool graph[10][10] = {false}; //隣接行列
bool visited[10] = {false};
int n, m;

int dfs(int bv, int depth)
{
    int res = 0;

    if (depth == n - 1)
    {
        // cout << "res" << ':' << bv << endl;
        return 1;
    }

    for (int v = 0; v < n; v++)
    {
        if (bv == v)
        {
            continue;
        }
        if (graph[bv][v] && graph[v][bv] && !visited[v])
        {
            visited[v] = true;
            // cout << "run:" << v << endl;
            res += dfs(v, depth + 1);
            visited[v] = false;
        }
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        graph[a[i]][b[i]] = true;
        graph[b[i]][a[i]] = true;
    }
    visited[0] = true;
    cout << dfs(0, 0) << endl;
}