#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

ll solve() {
    ll N, M, a, b;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    for ( int i = 0; i < M; i++ ) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll NN = (1 << N);

    function<int(int,int)> dfs = [&](int v, int b) {
        int r = 0;
        for ( int u : G[v] ) {
            int nb = b | (1<<u);
            if ( nb == b ) continue;
            if ( nb != NN-1 ) {
                r += dfs(u, nb);
            } else {
                r += 1;
            }
        }
        return r;
    };
    
    ll ans = dfs(0,1);
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}