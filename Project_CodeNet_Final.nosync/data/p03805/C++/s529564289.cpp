#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}
int n;
int ans = 0;
    vector<vector<int>> graph;
    vector<bool> visited;
void dfs(int cur){
    visited[cur] = true;
    REP(i, n){
        if(visited[i] == false){
            break;
        }
        if (i == n - 1){
            ans++;
        }
    }
    for (int i = 0; i < graph[cur].size(); i++){
        if (visited[graph[cur][i]] == true){
            continue;
        }
        dfs(graph[cur][i]);
    }
    visited[cur] = false;
}

signed main() {
    int m;
    cin >> n >> m;
    graph.resize(n);
    visited.resize(n);
    REP(i, m){
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    dfs(0);
    cout << ans << endl;
}