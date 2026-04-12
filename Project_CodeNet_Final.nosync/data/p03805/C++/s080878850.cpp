#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

int ans = 0;

void dfs(int pos, vector<vector<int>>& G, vector<bool>& visited){
    if(visited[pos]) return;
    visited[pos] = true;
    for(int v: G[pos]) dfs(v, G, visited);
    REP(i, G.size()){
        if(!visited[i]){
            visited[pos] = false;
            return;
        }
    }
    visited[pos] = false;
    ++ans;
    return;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    REP(i, M){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> visited(N, false);
    dfs(0, G, visited);
    cout << ans << endl;

    return 0;
}