#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
vector<int> g[maxn];
int col[maxn];
int deg[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> o;
    forn (i, n) {
        col[i] = -1;
        deg[i] = sz(g[i]);
        if (deg[i] <= 1)
            o.push_back(i);
    }
    forn (ii, sz(o)) {
        int u = o[ii];
        if (col[u] != -1)
            continue;
        int v = -1;
        for (int i: g[u]) {
            if (col[i] == -1)
                v = i;
        }
        //cerr << "cut " << u + 1 << ' ' << v + 1 << '\n';
        if (v == -1) {
            cout << "First\n";
            return 0;
        }
        col[v] = 1;
        col[u] = 0;
        for (int i: g[v]) {
            if (--deg[i] <= 1 && col[i] == -1)
                o.push_back(i);
        }
    }
    cout << "Second\n";
}
