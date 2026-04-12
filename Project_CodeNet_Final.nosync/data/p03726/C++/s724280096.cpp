#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector <int> g[N];

int sz[N];
int n;
bool used[N];
bool fnd = false;

void dfs(int v, int par) {
    //used[v] = true;
    for (auto t: g[v])
        if (t != par)
            dfs(t, v);
    int sum = 0;
    int odd = 0;
    for (auto t: g[v])
        if (t != par) {
            sum += sz[t];
            if (sz[t] % 2)
                odd++;
        }
    sz[v] = sum + 1;
    if ((n - sum - 1) % 2)
        odd++;
    if (odd >= 2) fnd = true;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    fr(i, n - 1) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }

    dfs(0, -1);
    if (fnd)
        cout << "First";
    else
        cout << "Second";
}
