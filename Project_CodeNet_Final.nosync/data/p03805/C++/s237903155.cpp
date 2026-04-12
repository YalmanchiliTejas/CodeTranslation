#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int n,m;
vector<vector<int>> graph(10);
vector<int> reached(10);

int dfs(int p, bool visited[10])
{
    bool all_visited = true;

    REP(i, n) {
        if(!visited[i]) {
            all_visited = false;
        }
    }
    if(all_visited) {
        return 1;
    }

    int ret = 0;

    REP(i, graph[p].size()) {
        int n = graph[p][i];
        if(visited[n]) {
            continue;
        }

        visited[n] = true;
        ret += dfs(graph[p][i], visited);
        visited[n] = false;
    }

    return ret;
}

int main() {
    cin >> n >> m;

    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool visited[10] = {};
    visited[0] = true;
    cout << dfs(0, visited) << endl;
}


