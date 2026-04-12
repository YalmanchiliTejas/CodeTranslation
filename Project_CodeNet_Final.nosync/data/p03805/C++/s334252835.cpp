#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}

bitset<8> adj[8];
int n, m;

int dfs(int node, bitset<8> visited){
    bool complete = true;
    if(visited.count() == n)
        return 1;
    int total = 0;
    for(int i = 0; i < n; ++i){
        if(adj[node][i] == 0) continue;
        if(visited[i]) continue;
        visited[i] = 1;
        total += dfs(i, visited);
        visited[i] = 0;
    }
    return total;
}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a - 1][b - 1] = adj[b - 1][a - 1] = 1;
    }

    bitset<8> visited;
    visited[0] = 1;

    cout << dfs(0, visited);

    return 0;
}
