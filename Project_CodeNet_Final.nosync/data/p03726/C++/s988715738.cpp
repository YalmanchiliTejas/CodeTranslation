
#include <algorithm>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr static int MAXN = 2e5;

int n;
vector <int> adj[MAXN];
bool vis[MAXN];
unordered_map <int, int> parity[MAXN];
// 1 = even
// 2 = odd

int calc(int u, int v) {
    if (parity[u].count(v))
        return parity[u][v];
    if (adj[v].size() == 1)
        return parity[u][v] = 1;

    int cnt1 = 0, cnt2 = 0;
    for (int w : adj[v]) {
        if (w == u)
            continue;
        int p = calc(v, w);
        if (p == 1)
            cnt1++;
        if (p == 2)
            cnt2++;
    }
    if (cnt1 >= 2) {
        cout << "First" << endl;
        exit(0);
    }
    if (cnt1 == 0)
        return parity[u][v] = 1;
    return parity[u][v] = 2;
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
        int cnt1 = 0, cnt2 = 0;
        for (int j : adj[i]) {
            int p = calc(i, j);
            if (p == 1)
                cnt1++;
            if (p == 2)
                cnt2++;
        }
        bool check = false;
        check |= (cnt1 >= 2);
        check |= (cnt2 == adj[i].size());
        if (check) {
            //cout << "CHOSE: " << i+1 << " " << adj[i].size() << endl;
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
}
