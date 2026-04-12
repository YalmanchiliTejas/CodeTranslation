#include "bits/stdc++.h"

using namespace std;
using ll = long long;

#define endl '\n'
#define FIO() ios_base::sync_with_stdio(0);cin.tie(NULL);

const int mx = 1e5 + 9;

ll cyc_len = 0, cyc_sum = 0;
vector <int> adj[mx];
bitset <mx> mark;

int main() {
    FIO();

    ll n, x, m;
    cin >> n >> x >> m;
    for (ll i = 0; i < m; i++) {
        ll j = (i * i) % m;
        adj[i].push_back(j);
    }

    ll ans = 0;
    while (n > 0) {
        if (mark[x]) break;
        ans += x;
        mark[x] = 1;
        x = adj[x][0];
        n--;
    }

    if (n > 0) {
        mark = 0;
        int y = x;
        while (!mark[y]) {
            cyc_len++;
            cyc_sum += y;
            mark[y] = 1;
            y = adj[y][0];
        }

        ll d = n / cyc_len, r = n % cyc_len;
        ans += (d * cyc_sum);
        for (int i = 0; i < r; i++) {
            ans += x;
            x = adj[x][0];
        }
    }

    cout << ans << endl;
}