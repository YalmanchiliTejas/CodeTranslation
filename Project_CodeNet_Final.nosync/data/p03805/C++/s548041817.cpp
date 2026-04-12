#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int G[n][n+1];
    memset(G, 0, sizeof(G));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }

    int perm[n];
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    int ans = 0;
    do {
        for (int i = 0; i < n - 1; i++) {
            if (!G[ perm[i] ][ perm[i + 1] ]) break;
            if (i == n - 2) ans++;
        }
    } while (next_permutation(perm, perm + n) && perm[0] == 0);
    cout << ans << endl;
}