#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    auto dfs = [&](auto &&dfs, int cur, int bit) -> int {
        if(bit == (1 << N) - 1) return 1;
        int res = 0;
        for(auto &to : G[cur]) {
            if(bit & (1 << to)) continue;
            res += dfs(dfs, to, bit | (1 << to));
        }
        return res;
    };
    cout << dfs(dfs, 0, 1) << '\n';
    return 0;
}
