#include <bits/stdc++.h>
using namespace std;

int adj[10][10];
int n, m;

int dfs(int now, int vis) {
    vis |= 1 << now;
    if (vis == (1 << n) - 1) return 1;
    
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (adj[now][i] && !(vis & (1 << i))) {
            ret += dfs(i, vis | (1 << i));
        }
    }
    return ret;
}

int main(void){
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a - 1][b - 1] = adj[b - 1][a - 1] = 1;
    }
    cout << dfs(0, 0) << "\n";
    return 0;
}
