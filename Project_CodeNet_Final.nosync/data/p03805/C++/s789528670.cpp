#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        edge[a][b] = edge[b][a] = 1;
    }
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = i;

    int ans = 0;
    do {
        int ok = 1;
        if (v[0] != 0) continue;
        for (int i = 0; i < n - 1; ++i) {
            if (!edge[v[i]][v[i + 1]]) {
                ok = 0;
                break;
            }
        }
        ans += ok;
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << "\n";
    return 0;
}
