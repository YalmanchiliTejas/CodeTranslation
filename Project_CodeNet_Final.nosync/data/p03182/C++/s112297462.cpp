#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second
const int MAXN = 200005;
ll INF = 1e18;

ll t[4 * MAXN];
ll tmx[4*MAXN];

void upd(int v, int tl, int tr, int l, int r, ll val)
{
    if (l > r) return;
    if (tl == l &&  tr == r)
    {
        t[v] += val;
        tmx[v] = tmx[v] + val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        upd(v*2, tl, tm, l, min(r,tm), val);
        upd(v*2+1, tm+1, tr, max(l,tm+1), r, val);
        tmx[v] = max(tmx[2*v], tmx[2*v+1]) + t[v];
    }
}

ll mx(int v, int tl, int tr, int l, int r) {
    if (l > r) return -INF;
    if (tl == l && tr == r) return tmx[v];
	int tm = (tl + tr) / 2;
	return max(mx(v*2, tl, tm, l, min(r,tm)),
        mx(v*2+1, tm+1, tr, max(l,tm+1), r));
}


pair <int, ll> l[MAXN];
pair < int, pair <int, ll> > r[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l[i].ff >> r[i].ff >> l[i].ss;
        r[i].ss.ff = l[i].ff;
        r[i].ss.ss = l[i].ss;
    }

    sort(l, l + m);
    sort(r, r + m);
    int li = 0, ri = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (li < m && l[li].ff <= i) {
            upd(1, 0, n, 0, l[li].ff-1, l[li].ss);
            li++;
        }
        while (ri < m && r[ri].ff < i) {
            upd(1, 0, n, 0, r[ri].ss.ff-1, -r[ri].ss.ss);
            ri++;
        }
        ll dp = mx(1, 0, n, 0, i-1);
        upd(1, 0, n, i, i, dp);
        ans = max(ans, dp);
    }

    cout << ans << endl;
}
