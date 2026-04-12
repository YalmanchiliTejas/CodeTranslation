#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace _gnu_pbds;
#define vb __int128
#define ll long long
#define ld long double
#define full(a) a.begin(),a.end()
#define fr(i,a,b) for(ll i = a ; i < b ; i++)
#define stoink stack<ll>
#define quu queue<ll>
#define quee queue<pair<ll,ll>>
#define vec vector <ll>
#define vecd vector<ld>
#define vg vector<vector<ll> >
#define eg vector<pair<ll,ll>>
#define vgw vector<vector<pair<ll,ll> > >
#define pa pair<ll,ll>
#define pb push_back
#define ff first
#define ss second
#define pre 0.00000000000000000001
#define inf 100000000000000000
#define mod 998244353
#define endl '\n'
ll n,m;
const int maxn = (int)(2e5 + 5);
vec tree(4 * maxn,0),lazy(4 * maxn,0);
void upd_lazy(ll ind,ll l,ll r) {
    if(lazy[ind] != 0) {
        tree[ind] += lazy[ind];
        if(l != r) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
}
void upd(ll ind,ll l,ll r,ll ql,ll qr,ll val) {
    upd_lazy(ind,l,r);
    if(r < l)
        return;
    if(qr < l || ql > r)
        return;
    if(ql <= l && r <= qr) {
        lazy[ind] = val;
        upd_lazy(ind,l,r);
        return;
    }
    ll mid = (l + r) / 2;
    upd(2 * ind,l,mid,ql,qr,val);
    upd(2 * ind + 1,mid + 1,r,ql,qr,val);
    tree[ind] = max(tree[2 * ind],tree[2 * ind + 1]);
}
ll query(int ind,ll l,ll r,ll ql,ll qr) {
    upd_lazy(ind,l,r);
    if(r < l ||  qr < ql)
        return 0;
    if(qr < l || ql > r)
        return - inf;
    if(ql <= l && r <= qr) {
        return tree[ind];
    }
    ll mid = (l + r) / 2;
    return max(query(2 * ind,l,mid,ql,qr),query(2 * ind + 1,mid + 1,r,ql,qr));
}
int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
    vgw qry(n);
    fr(i,0,m) {
        ll l,r,val;
        cin >> l >> r >> val;
        l--;r--;
        qry[r].pb({l,val});
    }
    fr(i,0,n) {
        ll maxi = query(1,0,n - 1,0,i - 1);
        if(maxi >= 0)
        upd(1,0,n-1,i,i,maxi);
        for(auto j : qry[i]) {
            upd(1,0,n - 1,j.ff,i,j.ss);
        }
    }
    ll ans = max(0LL,query(1,0,n-1,0,n-1));
    cout << ans;
    return 0;
}	