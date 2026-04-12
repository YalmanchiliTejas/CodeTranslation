#include <bits/stdc++.h>
#ifdef DEBUG
#include "_debug.cpp"
#include "callable.hpp/callable.hpp"
#endif
#define endl '\n'
using namespace std;
using ll = long long;
#define N 8
bool adj[N+1][N+1];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    memset(adj, false, sizeof adj);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
    }
    vector<int> nodes(n);
    iota(nodes.begin(), nodes.end(), 1);
    int ans = 0;
    do {
        bool can = nodes[0] == 1;
        for(int i = 1; i < n and can; i++) {
            can &= adj[nodes[i - 1]][nodes[i]];
        }
        ans += can;
    } while(next_permutation(nodes.begin(), nodes.end()));
    cout << ans << endl;
    return 0;
}
