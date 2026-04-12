#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define ld double
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (int i=(n);i>=(a);--i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define f first
// #define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// I am questioning life and universe and 
// everything else after looking at this

const ll MAXN = 3002;
ll dp[MAXN][MAXN][2];
ll n,a[MAXN];

ll rec(ll s,ll e,ll player){
    if(s > e) return 0;

    ll &ans = dp[s][e][player];

    if(ans != -1) return ans;

    if(!player) ans = max(a[s] + rec(s+1,e,1-player),a[e] + rec(s,e-1,1-player));
    else ans = min(-a[s] + rec(s+1,e,1-player),-a[e] + rec(s,e-1,1-player));
    
    return ans;
}

void solve(){
    cin>>n;
    FOR(i,1,n) cin>>a[i];

    memset(dp,-1,sizeof(dp));

    cout<<rec(1,n,0)<<endl;
}

signed main(){


    ll t;
    t = 1; 
    // cin>>t;
    FOR(tt,1,t){
        solve();
    }
    
}