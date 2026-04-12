#include <bits/stdc++.h>
using namespace std;

typedef long long int   ll;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;

#define all(x)          x.begin(), x.end()
#define kill(x)         return cout << x << endl, 0
#define X               first
#define Y               second
#define sep             ' '
#define endl            '\n'

ll pw(ll a, ll b, ll mod) {
    if (!b)    return 1;
    if (b & 1) return a * pw(a * a % mod, b / 2, mod) % mod;
    return pw(a * a % mod, b / 2, mod) % mod;
}

const ll N    = 1e5 + 10;
const ll MOD  = 1e9 + 7;
const ll INF  = 1e18;

int n, mark[N];
vector<int> adj[N];

void DFS(int u, int p) {
    for (int v : adj[u]) if (v != p) {
        DFS(v, u);
        mark[u] += (mark[v] == 0);
    }
    if (mark[u] >= 2) {
        cout << "First" << endl;
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    cout << (mark[1] ? "Second" : "First") << endl;
    return 0;
}