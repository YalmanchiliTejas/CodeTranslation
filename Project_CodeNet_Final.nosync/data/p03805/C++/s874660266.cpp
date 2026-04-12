#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


// int dfs(int cur) {
//     ll ans = 0;
//     visited[cur] = true;
//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) {
//             break;
//         }
//         if (i == n - 1) {
//             return 1;
//         }
//     }
//     for (int i = 0; i < g[cur].size(); i++) {
//         int next = g[cur][i];
//         cout << next << endl;
//         if (!visited[next]) {
//             ans += dfs(next);
//         }
//     }
//
//     return ans;
// }

int main() {
    int n, m;
    cin >> n >> m;
    bool g[n][n];
    int v[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = false;
        }
        v[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b] = g[b][a] = true;
    }

    ll ans = 0;
    do {
        if(v[0] == 0) {
            for (int i = 1; i < n; i++) {
                if (!g[v[i]][v[i - 1]]) {
                    break;
                }
                if (i == n - 1) {
                    ans++;
                }
            }
        } else {
            break;
        }
    } while (next_permutation(v, v + n));

    cout << ans << endl;


    return 0;
}
