#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_N = 2e5 + 10, INF = 1e15, MOD = 1e9 + 7, max_tree = 4 * max_N;
ll N, M;
vector<pair<ll, ll>> endings[max_N];
ll seg[max_tree], lazy[max_tree];

void update_lazy(ll t_idx, ll s, ll e)
{
    if (!lazy[t_idx])
        return;
    seg[t_idx] += lazy[t_idx];
    if (s != e)
    {
        lazy[t_idx * 2] += lazy[t_idx];
        lazy[t_idx * 2 + 1] += lazy[t_idx];
    }
    lazy[t_idx] = 0;
}

void seg_update(ll s, ll e, ll l, ll r, ll val, ll t_idx) // [s,e] of segment tree idx     and [l,r] is array update range
{
    update_lazy(t_idx, s, e);
    if(e < s)
        return ;
    if (l <= s && e <= r)
    {
        lazy[t_idx] = val;
        update_lazy(t_idx, s, e);
        return ;
    }
    if (e < l || r < s)
        return ;
    ll mid = (s + e) / 2;
    seg_update(s, mid, l, r, val, t_idx * 2);
    seg_update(mid + 1, e, l, r, val, t_idx *2 + 1);
    seg[t_idx] = max(seg[t_idx*2], seg[t_idx *2 + 1]);
}

ll seg_query(ll s, ll e, ll l, ll r, ll t_idx)
{
    update_lazy(t_idx, s, e);
    if(e < s || r < l)
        return 0;
    if (l <= s && e <= r)
        return seg[t_idx];
    if (e < l || r < s)
        return -INF;
    ll mid = (s + e) / 2;
    ll lres = seg_query(s, mid, l, r, t_idx * 2);
    ll rres = seg_query(mid + 1, e, l, r, t_idx *2 + 1);
    return max(lres, rres);
}

int main()
{
    cin >> N >> M;
    ll s, e, cost;
    for (int i = 0; i < M; ++i)
    {
        cin >> s >> e >> cost;
        endings[e].push_back({s, cost});
    }
    for (int i = 1; i <= N; ++i)
    {
        ll new_val = max(seg_query(1, N, 1, i - 1, 1), 0LL);
        seg_update(1, N, i, i, new_val, 1);
        for (auto interval : endings[i])
            seg_update(1, N, interval.first, i, interval.second, 1);
    }
    ll res = seg_query(1, N, 1, N, 1);
    res = max(res, 0LL);
    cout << res << "\n";
    return 0;
}