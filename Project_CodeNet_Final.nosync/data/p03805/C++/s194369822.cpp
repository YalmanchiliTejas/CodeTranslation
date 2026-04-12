#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 2e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m;
vector<vector<int>> G;
vector<bool> visited;
int ans = 0;
int cnt = 0;

void dfs(int v) {
    bool all_visited = true;
    rep(i,n) {
        if (!visited[i]) all_visited = false;
    }
    if (all_visited) {
        ans++;
        return;
    }

    for (int u : G[v]) {
        if (visited[u]) continue;
        visited[u] = true;
        dfs(u);
        visited[u] = false;
    }
    return;
}

int main() {
    cin >> n >> m;
    G.resize(n); visited.resize(n);
    visited[0] = true;
    int u,v;
    rep(i,m) {
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(0);

    cout << ans << endl;

}