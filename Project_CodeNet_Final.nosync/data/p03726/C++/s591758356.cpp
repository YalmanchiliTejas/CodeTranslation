#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

int n;
vector<int> graph[500000];
int col[500000];
int sz[500000];

void dfs(int v)
{
    col[v] = 1;
    sz[v] = 1;
    for (auto u : graph[v])
    {
        if (col[u] == 0)
        {
            dfs(u);
            sz[v] += sz[u];
        }
    }
}

int main()
{
    cin >> n;
    if (n % 2 == 1)
    {
        cout << "First";
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (auto u : graph[i])
        {
            if (min(sz[u], sz[i]) % 2 == 1) cnt++;
        }
        if (cnt != 1)
        {
            cout << "First";
            return 0;
        }
    }
    cout << "Second";
}
