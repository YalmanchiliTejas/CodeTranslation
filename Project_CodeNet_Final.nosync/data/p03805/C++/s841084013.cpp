#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <(n); i++)
using namespace std;
using ll = long long;

int cnt = 0;
int n, m;
vector<int> graph[10];

void dfs(int visited[], int now, int num_visited)
{
    if (num_visited == n)
    {
        cnt++;
        return;
    }
    for (auto next : graph[now])
    {
        if (visited[next] == 1) continue;
        visited[next] = 1;
        dfs(visited, next, num_visited + 1);
        visited[next] = 0;
    }
}

int main()
{
    cin >> n >> m;

    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int visited[n];
    rep(i, n) visited[i] = 0;
    visited[0] = 1;
    dfs(visited, 0, 1);

    cout << cnt << endl;
    return 0;
}