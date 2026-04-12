#include <bits/stdc++.h>


using namespace std;


const int MAXN = 100 * 1000 + 23;




int n;
vector<int> g[MAXN];


bool dfs(int, int);


int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v), g[v].push_back(u); 
    }
    if (dfs(0, -1))
        cout << "First";
    else
        cout << "Second";
    return 0;
}
bool dfs(int v, int p) {
    int cnt = 0;
    for (auto u : g[v])
        if (u != p)
            cnt += (dfs(u, v)? 1: 0);
    if (cnt > 1) {
        cout << "First";
        exit(0);
    }
    return cnt < 1;
}