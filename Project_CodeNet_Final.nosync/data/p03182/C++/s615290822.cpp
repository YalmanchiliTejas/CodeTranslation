#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll n, m;
ll tree[800009];
ll lazy[800009];
void push(ll v){
    tree[2*v] += lazy[v];
    lazy[2*v] += lazy[v];
    tree[2*v+1] += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}
void update(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(tl > r || tr < l)
        return;
    if(tl >= l && tr <= r){
        tree[v] += val;
        lazy[v] += val;
        return;
    }
    else{
        push(v);
        ll tm = (tl+tr)/2;
        update(2*v, tl, tm, l, r, val);
        update(2*v+1, tm+1, tr, l, r, val);
        tree[v] = max(tree[2*v], tree[2*v+1]);
    }
}
ll get(ll v ,ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l)
        return -1e18;
    if(tl >= l && tr <= r)
        return tree[v];
    else{
        push(v);
        ll tm = (tl+tr)/2;
        ll t1 = get(2*v, tl, tm, l, r);
        ll t2 = get(2*v+1, tm+1, tr, l, r);
        return max(t1, t2);
    }
}
ll ans;
ll dp[200009];
vector<pair<pll, ll>> seg;
multiset<pair<pll, ll>> rev;
ll curseg;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        seg.pb({{t1, t2}, t3});
    }
    sort(seg.begin(), seg.end());
    ll adval = 0;
    for(int i = 1; i <= n; ++i){
        while(i >= seg[curseg].ff.ff && curseg < m){
            update(1, 0, n, seg[curseg].ff.ff, seg[curseg].ff.ss, -seg[curseg].ss);
            rev.insert({{seg[curseg].ff.ss, seg[curseg].ff.ff}, seg[curseg].ss});
            adval += seg[curseg].ss;
            ++curseg;
        }
        while(rev.size() > 0){
            pair<pll,ll> tmp = *rev.begin();
            if(tmp.ff.ff >= i)
                break;
            rev.erase(rev.begin());
            update(1, 0, n, tmp.ff.ss, tmp.ff.ff, tmp.ss);
            adval -= tmp.ss;
        }
        dp[i] = adval + max((ll)0, get(1, 0, n, 0, i-1));
        update(1, 0, n, i, i, dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}