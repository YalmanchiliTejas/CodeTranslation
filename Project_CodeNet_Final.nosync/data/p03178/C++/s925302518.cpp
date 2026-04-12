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

const ll MAXN = 1e4 + 10;
const ll MAXD = 101;
ll dp[MAXN][MAXD][2];
ll a[MAXN];
const ll MOD = 1e9 + 7;
ll X,n;

ll rec(ll idx,ll val,ll tight){
    if(idx > n) {
        if(val == 0) return 1;
        else return 0;
    }

    ll &ans = dp[idx][val][tight];

    if(ans != -1) return ans;

    ans = 0;
    ll high = 9;
    if(tight) high = a[idx];

    FOR(i,0,high){
        ll n_t = tight; 
        if(i != high) n_t = 0;

        ans = (ans + rec(idx+1,(val + i)%X,n_t))%MOD;
    }

    return ans;
}

void solve(){
    string s; cin>>s;

    FOR(i,0,s.length()-1) a[i+1] = s[i]-'0';
    n = s.length(); cin>>X;

    MINUS(dp);

    cout<<(rec(1,0,1) - 1 + MOD)%MOD<<endl;
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