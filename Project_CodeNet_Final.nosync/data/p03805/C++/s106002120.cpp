#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m, ans = 0;
    vector<int> g[10];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<pair<int, int>> que;
    pair<int, int> s;
    s.first = 0;
    s.second = 0;
    que.push(s);
    while (!que.empty()) {
        auto p = que.front(); que.pop();
        p.second |= (1 << p.first);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (!(p.second & (1 << i))) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
            continue;
        }
        for (int i = 0; i < g[p.first].size(); i++) {
            if (!(p.second & (1 << g[p.first][i]))) {
                que.push({g[p.first][i], p.second});
            }
        }
    }
    cout << ans << endl;
}