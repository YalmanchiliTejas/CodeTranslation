#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(i, n) for(int i=0; i<=n; i++)
#define repr(i, n) for(int i=n; i>0; i--)
#define REPR(i, n) for(int i=n; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
template<class T> void puts(T x) { std::cout << x << std::endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, m;
vector<vector<int>> g;
bool visited[10];

int dfs(int u) {
    visited[u] = true;

    bool all_visited = true;
    rep(i, n) {
        if (!visited[i]) all_visited = false;
    }

    if (all_visited) return 1;

    int ret = 0;

    for (int v: g[u]) {
        if (!visited[v]) {
            visited[v] = true;
            ret += dfs(v);
            visited[v] = false;
        }
    }

    return ret;
}


int main() {
    cin >> n >> m;
    g.resize(n);
    rep(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    cout << dfs(0) << endl;
}
