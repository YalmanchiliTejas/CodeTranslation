#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
bool chmin(ll& a, ll b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
bool chmax(ll& a, ll b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
struct edge {
    ll to, cost;
};
vector<edge> g[MAX_N];
vl visited(MAX_N, 0);
vector<vl> bubunki(MAX_N), ruisekiL(MAX_N), ruisekiR(MAX_N);
vl par(MAX_N), oya(MAX_N), oya_zibun(MAX_N);
vl dfs_takasa(MAX_N, 0), ANS(MAX_N, 0);
ll dfs(ll x) {
    visited[x] = 1;
    bubunki[x] = vl(g[x].size(), 0);
    ll t = 0;
    rep(i, g[x].size()) {
        ll to = g[x][i].to, cost = g[x][i].cost;
        if (visited[to] == 0) {
            par[to] = x;
            oya_zibun[to] = i;
            dfs(to);
            bubunki[x][i] = dfs_takasa[to] + cost;
            chmax(t, bubunki[x][i]);
        } else
            oya[x] = i;
    }

    return dfs_takasa[x] = t;
}

void dfs2(ll x) {
    visited[x] = 1;

    ll a = 0, b = 0;
    ruisekiL[x].push_back(0);
    ruisekiR[x].push_back(0);
    rep(i, g[x].size()) {
        a = max(a, bubunki[x][i]);
        b = max(b, bubunki[x][g[x].size() - 1 - i]);

        ruisekiL[x].push_back(a);
        ruisekiR[x].push_back(b);
    }

    reverse(all(ruisekiR[x]));

    for (edge i : g[x]) {
        if (visited[i.to] == 0) {
            ANS[i.to] = dfs_takasa[i.to];
            ll b = oya_zibun[i.to];
            bubunki[i.to][oya[i.to]] =
                max(ruisekiL[x][b] + i.cost, ruisekiR[x][b + 1] + i.cost);
            ANS[i.to] = max({dfs_takasa[i.to], bubunki[i.to][oya[i.to]]});
            dfs2(i.to);
        }
    }
}

int main() {
    cin >> n;
    rep(i, n - 1) {
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }

    dfs(0);
    visited = vl(n, 0);

    ANS[0] = dfs_takasa[0];
    dfs2(0);

    rep(i, n) { cout << ANS[i] << endl; }
}
