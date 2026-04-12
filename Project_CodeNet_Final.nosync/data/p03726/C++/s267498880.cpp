/* be name khoda */
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

#define forifrom(i, s, n) for (ll i = s; i < n; ++i)
#define fori(i, n) forifrom(i, 0, n)

// ------------------------------------------------------------------

const ll maxn = 100010;

ll n, notsat[maxn];
vector<ll> g[maxn];

void dfs(ll x, ll par) {
    notsat[x] = 1;
    for (auto y : g[x]) if (y != par) {
        dfs(y, x);
        if (notsat[y]) {
            if (notsat[x]) notsat[x] = 0;
            else {
                cout << "First\n";
                exit(0);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    fori (i, n - 1) {
        ll a, b; cin >> a >> b; --a, --b;
        g[a].emplace_back(b), g[b].emplace_back(a);
    }
    dfs(0, 0);
    if (notsat[0]) cout << "First\n";
    else cout << "Second\n";

}
