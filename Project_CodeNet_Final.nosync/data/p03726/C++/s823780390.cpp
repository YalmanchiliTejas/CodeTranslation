#include <bits/stdc++.h>
using namespace std;
int solve(const vector<vector<int>> &G) {
    vector<int> conn(G.size()), del(G.size());
    queue<int> Q;
    for (int i = 0; i < G.size(); i++) {
        conn[i] = G[i].size();
        if (conn[i] == 1) Q.push(i);
    }
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        if (del[node]) continue;
        if (conn[node] == 0) return 0;
        del[node] = 1;
        for (int next : G[node]) if (!del[next]) {
            del[next] = 1;
            for (int next2 : G[next]) if (!del[next2]) {
                conn[next2] -= 1;
                if (conn[next2] == 1) Q.push(next2);
            }
        }
    }
    return 1;
}
int main() {
    int N; cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cout << (solve(G) == 0 ? "First" : "Second") << endl;
    return 0;
}
