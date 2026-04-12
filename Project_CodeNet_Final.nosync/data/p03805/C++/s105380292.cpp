#include<bits/stdc++.h>

using namespace std;

int main(void) {
    long n, m;
    cin >> n >> m;

    vector<vector<long>> G(n);
    for(long i=0; i<m; i++) {
        long a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    long r = 0;
    {
        auto dfs = [&](auto dfs, long cur, long mask) -> void {
            if(mask == (1l<<n)-1) r++;

            for(auto v: G[cur]) {
                if((mask >> v)&1) continue;
                dfs(dfs, v, mask | (1l<<v));
            }
        };

        dfs(dfs, 0, 1);
    }
    cout << r << endl;
}
