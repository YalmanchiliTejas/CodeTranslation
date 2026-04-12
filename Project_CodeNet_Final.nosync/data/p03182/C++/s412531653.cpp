#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define ld long double
#define ft first
#define sd second
using namespace std;

const int N = 2e5 + 9;


ll tr[4 * N], lz[4 * N], f[N];
const ll inf = 1e18;

void upd(int x, int l, int r, int ul, int ur, ll diff) {
    if (lz[x] != 0) {
        tr[x] += lz[x];
        if (l != r) {
            lz[2 * x] += lz[x];
            lz[2 * x + 1] += lz[x];
        }
        lz[x] = 0;
    }
    if (l > r || l > ur || r < ul)
        return;
    if (l >= ul && r <= ur) {
        tr[x] += diff;
        if (l != r) {
            lz[2 * x] += diff;
            lz[2 * x + 1] += diff;
        }
        return;
    }
    int m = (l + r) / 2;
    upd(2 * x, l, m, ul, ur, diff);
    upd(2 * x + 1, m + 1, r, ul, ur, diff);
    tr[x] = max(tr[2 * x], tr[2 * x + 1]);
}


ll qry(int x, int l, int r, int ql, int qr) {
    if (lz[x] != 0) {
        tr[x] += lz[x];
        if (l != r) {
            lz[2 * x] += lz[x];
            lz[2 * x + 1] += lz[x];
        }
        lz[x] = 0;
    }
 
    if (l > r || l > qr || r < ql)
        return -inf;
    if (l >= ql && r <= qr)
        return tr[x];

    int m = (l + r) / 2;
    return max(qry(2 * x, l, m, ql, qr), qry(2 * x + 1, m + 1, r, ql, qr));
}


pair<pair<int, int>, ll> q[N];
vector<int> st[N], ed[N];
signed main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> q[i].ft.ft >> q[i].ft.sd >> q[i].sd;
        q[i].ft.ft++; q[i].ft.sd++;
        st[q[i].ft.ft].pb(i);
        ed[q[i].ft.sd].pb(i);
    }
    n++;
    for(int i = 2; i <= n; i++) {
        for(int j: st[i]) {
            upd(1, 1, n, 1, q[j].ft.ft-1, q[j].sd);
        }
        f[i] = qry(1,1,n,1, i-1);
        upd(1,1,n,i,i,f[i]);
        for(int j: ed[i]) {
            upd(1,1,n, 1, q[j].ft.ft-1, -q[j].sd);
        }
    }
    ll ans = 0;
    // cout << f[2] << endl;
    for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << "\n";
    
    return 0;
}