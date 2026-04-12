
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr static int MAXN = 2e5;

int n;
vector <int> adj[MAXN];
bool vis[MAXN];
unordered_map <int, int> parity[MAXN];

int calc(int u, int v) {
    if (parity[u].count(v))
        return parity[u][v];
    if (adj[v].size() == 1)
        return parity[u][v] = 1;

    int cnt = 0;
    for (int w : adj[v])
        if (w != u && calc(v, w) == 1)
            cnt++;

    if (cnt >= 2) {
        cout << "First" << endl;
        exit(0);
    }
    return parity[u][v] = (cnt == 0 ? 1 : 2);
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j : adj[i])
            if (calc(i, j) == 1)
                cnt++;
        if (cnt >= 2 || cnt == 0) {
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
}
