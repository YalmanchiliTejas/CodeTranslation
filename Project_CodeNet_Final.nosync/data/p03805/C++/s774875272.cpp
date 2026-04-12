#include <bits/stdc++.h>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    int g[10][50];
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            g[i][j] = 0;
        }
    }

    while (E--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }

    vector<int> vt;
    for (int i = 1; i < V; ++i) {
        vt.push_back(i);
    }

    int ans = 0;
    do {
        bool flag = true;
        if (g[0][vt[0]] == 0) flag = false;
        for (int i = 0; i < vt.size() - 1; ++i) {
            if (g[vt[i]][vt[i + 1]] == 0) {
                flag = false;
            }
        }
        if (flag) ans++;
    } while (next_permutation(vt.begin(), vt.end()));

    cout << ans << endl;
    return 0;
}