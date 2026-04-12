#include "bits/stdc++.h"
using namespace std;

const int N = 10;
vector< int> conn[N];
bool seen[N];
int n, m, res;

void dfs(int u, int k) {
    if(k == n) {
        res++;
        return;
    }

    for(int v: conn[u]) {
        if(seen[v]) continue;
        seen[v] = true;
        dfs(v, k + 1);
        seen[v] = false;
    }
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        conn[a].emplace_back(b);
        conn[b].emplace_back(a);
    }

    seen[1] = true;
    dfs(1, 1);
    cout << res << endl;
}