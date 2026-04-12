#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define sz(x) (int)(x.size())
vector<vector<int>> g(82);
vector<bool> visited(82, false);
void dfs(int v) {
    visited[v] = true;
    for (auto &u : g[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int ind(int i, int j) {
    return i * 8 + j;
}
pair<int, int> rind(int x) {
    return {x / 8, x % 8};
} 
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    string s[h];
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') continue;
            if (i + 1 < h && s[i + 1][j] == '#'){
                g[ind(i, j)].push_back(ind(i + 1, j));
            } else if (j + 1 < w && s[i][j + 1] == '#'){
                g[ind(i, j)].push_back(ind(i, j + 1));
            }
        }
    }
    dfs(0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#' && !visited[ind(i, j)]) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }
    cout << "Possible\n";
}