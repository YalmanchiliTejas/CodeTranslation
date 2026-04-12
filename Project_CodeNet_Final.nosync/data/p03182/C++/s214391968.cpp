#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

#define fori(a, n) for(ll (a) = 0; a < (n); ++a)
#define forI(a, n) for(ll (a) = 1; a <= (n); ++a)
#define pll pair<ll, ll>
#define pt pair<ll, ll>
#define x first
#define ff first
#define y second
#define ss second

const ll MAXN = 4e5 + 1;
const ll INF = 9e18;
const ll mod = 1e9 + 7;

ll n, m;

ll t[MAXN * 4];
ll a[MAXN * 4];
vector<pll> ln[MAXN];

void push(ll v){
    t[v] += a[v];
    a[v * 2] += a[v];
    a[v * 2 + 1] += a[v];
    a[v] = 0;
}

void add(ll v, ll l0, ll r0, ll l, ll r, ll val){
    if(l >= r) return;
    if(l0 == l && r0 == r){
        a[v] += val;
        return;
    }
    push(v);
    ll mid = (l0 + r0) >> 1;
    add(v * 2, l0, mid, l, min(r, mid), val);
    add(v * 2 + 1, mid, r0, max(l, mid), r, val);
    push(v * 2), push(v * 2 + 1);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

ll q(ll v, ll l0, ll r0, ll l, ll r){
    if(l >= r) return 0;
    push(v);
    if(l0 == l && r == r0){
        return t[v];
    }
    ll mid = (l0 + r0) >> 1;
    return max(q(v * 2, l0, mid, l, min(r, mid)),
               q(v * 2 + 1, mid, r0, max(l, mid), r));
}


void solve(){
    cin >> n >> m;
    fori(i, m){
        ll a, b, c;
        cin >> a >> b >> c;
        ln[b].emplace_back(a, c);
    }
    forI(i, n){
        add(1, 0, n + 1, i, i + 1, q(1, 0, n + 1, 0, i));
        for(auto e: ln[i]){
            add(1, 0, n + 1, e.ff, i + 1, e.ss);
        }
    }
    ll ans = 0;
    forI(i, n) ans = max(ans, q(1, 0, n + 1, i, i + 1));
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
