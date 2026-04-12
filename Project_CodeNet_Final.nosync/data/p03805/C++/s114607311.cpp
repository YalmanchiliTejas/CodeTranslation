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

bool path[10][10]; //隣接行列
bool visited[10];  //訪問したかどうか

int dfs(int depth, int from)
{
    if (depth == 0)
    {
        return 1;
    }

    int ans = 0;

    for (int v = 0; v < 10; v++)
    {
        if (v == from)
        {
            continue;
        }
        if (path[from][v] && !visited[v])
        {
            visited[v] = true;
            ans += dfs(depth - 1, v);
            visited[v] = false;
        }
    }

    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--; // 0-indexedに変える
        path[a[i]][b[i]] = true;
        path[b[i]][a[i]] = true;
    }

    visited[0] = true;

    cout << dfs(n - 1, 0) << endl;
}