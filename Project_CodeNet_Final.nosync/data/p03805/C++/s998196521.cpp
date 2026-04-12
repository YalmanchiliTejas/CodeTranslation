#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 10;

struct edge {int to, cost;}; // 辺
vector<edge> graph[MAX]; // 隣接リスト
bool visited[MAX]; // 訪問状況

void dfs(int s, int i, int n, int &cnt) { // 始点, 今の深さ、頂点の数、パスの数
    if (i == n) {
        cnt++;
        return;
    }
    visited[s] = true;
    for (edge e : graph[s]) {
        if (not visited[e.to]) {
            dfs(e.to, i+1, n, cnt);
        }
    }
    visited[s] = false;
}

int main() {
    // input
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back({v, 0});
        graph[v].push_back({u, 0});
    }
    // solve
    int cnt = 0;
    dfs(0, 1, n, cnt);
    // output
    cout << cnt << endl;
}