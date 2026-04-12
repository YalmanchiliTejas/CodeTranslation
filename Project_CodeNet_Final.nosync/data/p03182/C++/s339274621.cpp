#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
#define endl "\n"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll N = 2e5 + 10, inf = 1e18 + 10, mod = 1e9 + 7;
ll t[4 * N], c[4 * N], x[N], d[N], L[N], R[N], ans;
vector <int> a[N];
void push(int v, int tl, int tr)
{
    if(c[v])
    {
        t[v] += c[v];
        if (tl != tr){
            c[v + v] += c[v];
            c[v + v + 1] += c[v];
        }
        c[v] = 0;
    }
}
ll ma(int v, int tl, int tr, int l, int r)
{
    push(v, tl, tr);
    if(l <= tl && tr <= r)return t[v];
    else if(tr < l || r < tl)return -inf;
    else
    {
        int mid = (tl + tr) / 2;
        return max(ma(v + v, tl, mid, l, r), ma(v + v + 1, mid + 1, tr, l, r));
    }
}
void up(int v, int tl, int tr, int l, int r, ll val)
{
    push(v, tl, tr);
    if(l <= tl && tr <= r)
    {
        c[v] += val;
        push(v, tl, tr);
    }
    else if(tr < l || r < tl)return;
    else
    {
        int mid = (tl + tr) / 2;
        up(v + v, tl, mid, l, r, val);
        up(v + v + 1, mid + 1, tr, l, r, val);
        t[v] = max(t[v + v], t[v + v + 1]);
    }
}
main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("prices.in", "r", stdin);
    //freopen("prices.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> L[i] >> R[i] >> x[i];
        a[L[i]].pb(i);
        a[R[i]].pb(-i);
    }
    for(int i = 1; i <= n; i++)
    {
        for(auto j : a[i])
        {
            if(j > 0)up(1, 0, n, 0, i - 1, x[j]);
        }
        d[i] = ma(1, 0, n, 0, i - 1);
        up(1, 0, n, i, i, d[i]);
        for(auto j : a[i])
        {
            if(j < 0)
            {
                up(1, 0, n, 0, L[-j] - 1, -x[-j]);
            }
        }
        ans = max(ans , d[i]);
    }
    cout << ans;
}
