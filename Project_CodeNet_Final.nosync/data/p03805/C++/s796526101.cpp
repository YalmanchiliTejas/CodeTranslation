#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const ll mod = 1000000007;
const int MAX_V = 8;

int n, m, ans = 0;
Graph G(MAX_V, vector<int>(MAX_V));
vector<int> visited(MAX_V);

void dfs(int v) {

    int flag = 1;
    rep(i, n) {
        if(!visited[i]) {
            flag = 0;
        }
    }

    if(flag) {
        ans++;
    }
    
    rep(u, n) {
        if(G[v][u] && !visited[u]) {
            visited[u] = 1;
            dfs(u);
            visited[u] = 0;
        }
    }

}

int main() {

    cin >> n >> m;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;  b--;
        G[a][b] = G[b][a] = 1;
    }

    visited[0] = 1;    

    dfs(0);

    cout << ans << endl;
    return 0;
}