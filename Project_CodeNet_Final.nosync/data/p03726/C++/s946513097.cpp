#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int sz[100001];
vector<int> G[100001];

bool dfs(int u, int p) {
    sz[u] = 1;
    int cnt = 0;
    for (int v : G[u]) if (v != p) {
        if (dfs(v, u)) return true;
        cnt += sz[v], sz[u] ^= sz[v];
    }
    return cnt > 1;
}

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }
    cout << ((N & 1) || dfs(1, 0) ? "First" : "Second");
}