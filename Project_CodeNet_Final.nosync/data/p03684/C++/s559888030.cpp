#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvl;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(c) (c).begin(), (c).end()
#define MOD 1000000007
#define MAX 1e5 + 10

vector<int> p;

int dsu_get (int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
    a = dsu_get (a);
    b = dsu_get (b);
    if (rand() & 1)
        swap (a, b);
    if (a != b)
        p[a] = b;
}

int main(){
#ifdef HOME
    freopen("kek.in", "r", stdin);
    freopen("kek.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    p.resize(n);
    vpll x(n);
    vpll y(n);
    vector<pair<ll, pll>> g;
    for(int i = 0; i < n; i++) {
        cin >> x[i].ff >> y[i].ff;
        x[i].ss = i;
        y[i].ss = i;
    }
    sort(all(x));
    sort(all(y));
    for(int i = 0; i < n - 1; i++)
        g.pb(mp(abs(x[i].ff - x[i + 1].ff), mp(x[i].ss, x[i + 1].ss)));
    for(int i = 0; i < n - 1; i++)
        g.pb(mp(abs(y[i].ff - y[i + 1].ff), mp(y[i].ss, y[i + 1].ss)));
    sort(all(g));

    ll m = g.size();
    ll cost = 0;
    for (int i=0; i<n; ++i)
        p[i] = i;
    for (int i=0; i<m; ++i) {
        int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
        if (dsu_get(a) != dsu_get(b)) {
            cost += l;
           // res.push_back (g[i].second);
            dsu_unite (a, b);
        }
    }
    cout << cost;
    return 0;
}