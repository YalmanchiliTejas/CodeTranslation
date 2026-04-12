#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
using Graph = vector<vector<int>>;
Graph G;

int dfs(int v, vector<bool> &seen) {
    bool end = true;
    for (int i=0; i < seen.size(); ++i) {
        if (!seen[i] && i != v) {
            end = false;
        }

    }

    if (end) {
        return 1;
    }

    int res = 0;
    seen[v] = true;
    for (auto nv : G[v]) {
        if (seen[nv]) {
            continue;
        }

        res += dfs(nv, seen);
    }

    seen[v] = false;
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;
    G.assign(N, vector<int>());
    for (int i=0; i<M; i++) {
        int n, m;
        cin >> n >> m;
        G[n-1].emplace_back(m-1);
        G[m-1].emplace_back(n-1);
    }

    vector<bool> seen(N, false);
    int res = dfs(0, seen);
    cout << res << endl;
    return 0;
}