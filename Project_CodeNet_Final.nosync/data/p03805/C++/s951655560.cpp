#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef unsigned long long ull;

int N, M;
vector<int> visited;
vector<vector<int>> G;
int numVisited = 0;
int res = 0;

void dfs(int nowNode) {
    visited[nowNode] = 1;
    ++numVisited;
    if (numVisited == N)
        ++res;

    int next;
    rep (i, G[nowNode].size()) {
        next = G[nowNode][i];
        if (!visited[next])
            dfs(next);
    }

    visited[nowNode] = 0;
    --numVisited;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    
    G = vector<vector<int>>(N);
    visited = vector<int>(N, 0);
    
    rep (i, M) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0);
    cout << res << "\n";
}