#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> x(9);
bool visited[9] = {};

long dfs(int a, int d) {
    if (visited[a])
        return 0;
    if (d == n-1)
        return 1;
    visited[a] = true;
    long cnt = 0;
    for (int b: x[a]) {
        cnt += dfs(b, d+1);
    }
    visited[a] = false;
    return cnt;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        x[a].push_back(b);
        x[b].push_back(a);
    }
    cout << dfs(1, 0) << endl;
}