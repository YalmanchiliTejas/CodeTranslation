#include <bits/stdc++.h>

using namespace std;

bool pass_check(vector<bool> &passed) {
    for (int i = 0; i < passed.size(); i++) if (!passed[i]) return false;
    return true;
}

void dfs(vector<vector<int>> &graph, vector<bool> &passed, int vertex, int &cnt) {
    if (pass_check(passed)) {
        cnt++;
        return;
    }

    for (int x : graph[vertex]) {
        if (passed[x]) continue;
        passed[x] = true;
        dfs(graph, passed, x, cnt);
        passed[x] = false;
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<bool> passed(n, false);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnt = 0;
    passed[0] = true;
    dfs(graph, passed, 0, cnt);

    cout << cnt << endl;
    return 0;
}