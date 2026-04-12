#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)


int dfs(int i, auto& visited, auto& llst)
{
    visited[i] = true;

    int visited_cnt = 0;
    rep(k, visited.size()) if (visited[k]) ++visited_cnt;
    if (visited_cnt == llst.size()) {
        visited[i] = false;
        return 1;
    }

    int cnt = 0;
    for (auto j: llst[i]) {
        if (visited[j]) continue;
        cnt += dfs(j, visited, llst);
    }
    visited[i] = false;

    return cnt;
}


int main()
{
    int N, M, a, b;
    cin >> N >> M;
    vector<vector<int>> llst(N);
    rep(i,M) {
        cin >> a >> b; a--; b--;
        llst[a].push_back(b);
        llst[b].push_back(a);
    }

    vector<bool> visited(N, false);
    cout << dfs(0, visited, llst) << endl;
}