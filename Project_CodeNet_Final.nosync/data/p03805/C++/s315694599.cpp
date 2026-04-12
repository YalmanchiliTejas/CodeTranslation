#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int ans = 0;
vector<vector<int>> field;
vector<bool> visited;

void dfs(int x, int remain);

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> path(n);
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    rep(i, m) {
        cin >> a >> b;
        path.at(a - 1).push_back(b - 1);
        path.at(b - 1).push_back(a - 1);
    }
    field = path;
    dfs(0, n - 1);
    cout << ans << endl;
}

void dfs(int x, int remain) {
    if(remain == 0) {
        ans++;
        return;
    }
    visited.at(x) = true;
    rep(i, field.at(x).size()) {
        if(!visited.at(field.at(x).at(i))) dfs(field.at(x).at(i), remain - 1);
    }
    visited.at(x) = 0;
    return;
}

