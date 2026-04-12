#include<bits/stdc++.h>

using namespace std;


using Graph = vector<vector<int>>;

int N, M;
Graph G;

vector<bool> visit;

int depth = 0;
int ans = 0;


void dfs(int from, int to) {
    visit[to] = true;
    depth++;
    if (depth == N) ans++;
    //cout << "depth" << depth << endl;
    for (auto next : G[to]) {
        if (visit[next]) continue;
        if (next == from) continue;
        dfs(to, next);
    }
    visit[to] = false;
    depth--;
}


void solve() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    visit.resize(N);

    dfs(-1, 0);

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}