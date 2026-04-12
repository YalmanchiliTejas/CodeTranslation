#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> adj(n, vector<bool>(n, false));
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = true;
    }

    vector<int> v(n);
    rep(i, 0, n) v[i] = i;

    int ans = 0;
    do {
        if (v[0] != 0) continue;

        bool flag = true;
        rep(i, 0, n - 1) {
            if (!adj[v[i]][v[i + 1]]) flag = false;
        }

        if (flag) ans++;

    } while (next_permutation(v.begin(), v.end()));
    
    cout << ans << endl;
    
    return 0;
}