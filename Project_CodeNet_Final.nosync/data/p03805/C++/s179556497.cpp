#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int G[n][n] = {};
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    int perm[n + 1];
    for (int i = 0; i < n; i++) perm[i] = i;
    int ans = 0;
    do {
        int flag = 1;
        for (int i = 0; i < n - 1; i++) {
            if (G[perm[i]][perm[i + 1]] == 0) flag = 0;
        }
        if (flag) ans++;

    } while (next_permutation(perm, perm + n) && perm[0] == 0);
    cout << ans << endl;
}