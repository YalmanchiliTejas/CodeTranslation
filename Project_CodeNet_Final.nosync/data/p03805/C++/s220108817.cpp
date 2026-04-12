#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(8, vector<int>());

void dfs(const int v, int &cnt, vector<bool> &done) {    
    done.at(v) = true;

    bool go = false;
    for (int i = 0; i < (int)G[v].size(); i++) {
        if (!done.at(G[v].at(i))) {
            go = true;
            dfs(G[v].at(i), cnt, done);
        }
    }

    if (!go) {
        bool all = true;
        for (int i = 0; i < (int)done.size(); i++) {
            if (!done.at(i)) {
                all = false;
                break;
            }
        }
        if (all) cnt++;
    }

    done.at(v) = false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    int cnt = 0;
    vector<bool> done(n);
    dfs(0, cnt, done);

    cout << cnt << endl;
}   