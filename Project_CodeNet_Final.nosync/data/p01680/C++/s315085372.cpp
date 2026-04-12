#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1e9+7;

void dfs(int v, vector<bool>& used, vector<vector<int>> const& g) {
    used[v] = true;
    for(auto to : g[v]) {
        if(!used[to]) {
            dfs(to, used, g);
        }
    }
}

int main() {
    int N, M;
    while(cin >> N >> M, N) {
        vector<vector<int>> g(N);
        for(int i=0; i<M; ++i) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int cnt = 0;
        vector<bool> used(N);
        for(int i=0; i<N; ++i) {
            if(!used[i]) {
                cnt++;
                dfs(i, used, g);
            }
        }
        ll res = 1;
        while(cnt-- > 0) {
            (res *= 2) %= mod;
        }
        cout << res + (M != 0) << endl;
    }
}
