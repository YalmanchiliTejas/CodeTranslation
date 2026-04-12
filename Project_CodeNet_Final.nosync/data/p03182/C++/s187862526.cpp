#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define endl '\n'
#define ld long double
#define FOR(i,a,n) for (ll i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (ll i=(n);i>=(a);--i)
#define FI(i,n) for (ll i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define MINUS(a) memset((a),-1,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
#define sz(x) (ll)x.size()
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
 
// I want to be the very best, like no one ever was, I will battle everyday to claim my rightful place
// Not gonna give up until it's over
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
// I am questioning life and universe and 
// everything else after looking at this

const ll MAXN = 2e5 + 10;
ll seg[4*MAXN],lazy[4*MAXN];
vector<pair<ll,ll>> L[MAXN],R[MAXN];

void propogate(ll node,ll s,ll e){
    seg[node] += lazy[node];
    if(s != e){
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(ll node,ll s,ll e,ll qs,ll qe,ll val){
    propogate(node,s,e);
    if(s > e || qs > e || qe < s) return;

    if(qs <= s && e <= qe){
        lazy[node] += val;
        propogate(node,s,e);
        return;
    }

    ll mid = (s+e)>>1;
    update(2*node,s,mid,qs,qe,val);
    update(2*node+1,mid+1,e,qs,qe,val);
    seg[node] = max(seg[2*node],seg[2*node+1]);
}

ll query(ll node,ll s,ll e,ll qs,ll qe){
    propogate(node,s,e);
    if(s > e || qs > e || qe < s) return -1e16;

    if(qs <= s && e <= qe) return seg[node];

    ll mid = (s+e)>>1;

    return max(query(2*node,s,mid,qs,qe),query(2*node+1,mid+1,e,qs,qe));
}

void solve(){
    ll n,m; cin>>n>>m;

    FOR(i,1,m){
        ll l,r,a; cin>>l>>r>>a;
        L[l].push_back({l-1,a});
        R[r].push_back({l-1,a});
    }

    ll ans = 0;

    FOR(i,1,n){
        for(auto x:L[i]) update(1,0,n,0,x.first,x.second);
        
        ll t_ans = query(1,0,n,0,i-1);
        ans = max(ans,t_ans);
        update(1,0,n,i,i,t_ans);

        for(auto x:R[i]) update(1,0,n,0,x.first,-x.second);
    }

    cout<<ans<<endl;
}

signed main(){
 
   FastRead;    
 
    ll t;
    t = 1; 
    // cin>>t;
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}