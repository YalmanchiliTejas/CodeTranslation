/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.16 16:53:00
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int n;
vector<vector<int>> g;
int dfs(int v, int p = -1) {
    vector<int> cnt(3,0);
    for(int u : g[v]) {
        if (p == u) continue;
        cnt[dfs(u,v)+1]++;
    }
    if (cnt[1] >= 2) return 1;
    if (cnt[2] >= 1) return 1;
    if (cnt[1] == 1) return -1;
    return 0;
}
int main() {
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n-1; i++) {
        int a,b;cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = dfs(0);
    if (ans != -1) {
        puts("First");
    }
    else {
        puts("Second");
    }
    return 0;
}