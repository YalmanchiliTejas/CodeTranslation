#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

const int MAX = 8;
bool G[MAX][MAX];

int dfs(int v, int n, bool visited[MAX]) {
    bool all_visited = true;

    rep(i, n) {
        if(!visited[i]) {
            all_visited = false;
        }
    }

    if(all_visited) {
        return 1;
    }

    int ret = 0;

    rep(i, n) {
        if(!G[v][i]) {
            continue;
        }
        if(visited[i]) {
            continue;
        }

        visited[i] = true;

        ret += dfs(i, n, visited);

        visited[i] = false;
    }

    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;  b--;
        G[a][b] = G[b][a] = true;
    }

    bool visited[MAX];
    rep(i, n) {
        visited[i] = false;
    }
    visited[0] = true;
    
    cout << dfs(0, n, visited);
    
    cout << endl;
    return 0;
}