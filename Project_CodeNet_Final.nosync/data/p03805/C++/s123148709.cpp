#include "bits/stdc++.h"
using namespace std;

#define OUT(x)  cerr << #x << " = " << x << endl;
#define all(x)  x.begin(), x.end()
#define mp      make_pair
#define pii     pair<int, int>
#define piii    pair<int, pair<int, int>>

vector<int> g[10];
bool used[10];
int n;
int ans = 0;

void dfs(int v, int cnt) {
        if (cnt == n) {
                ans ++;
                return;
        }
        for (int u : g[v]) if (!used[u]) {
                used[u] = true;
                dfs(u, cnt + 1);
                used[u] = false;
        }
}
                                   
int main() {
        int i, j;
        int m;
        cin >> n >> m;
        for (i = 0; i < m; i ++) {
                int a, b;
                cin >> a >> b;
                a --, b --;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        used[0] = true;
        dfs(0, 1);
        cout << ans << endl;
        return 0;
}

