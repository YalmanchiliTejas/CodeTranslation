#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+5;

int n, t[MAXN], v;
vector<int> g[MAXN];
int s[MAXN];

void dfs(int v, int f = -1) {
    s[v] = 1;
    int ct = 0;
    for (int u : g[v]) {
        if (u != f) {
            dfs(u, v);
            s[v] += s[u];
            ct += s[u]%2;
        }
    }
    ct += (n-s[v])%2;
    if (ct >= 2) {
        cout << "First\n";
        exit(0);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);

    cout << "Second\n";
    return 0;
}