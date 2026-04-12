// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define ll int
#define bits_count __builtin_popcountll
#define endl '\n'
#define double long double
#define ld double
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

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 3005;
int n,S; 
int a[MAXN];

int dp[MAXN][MAXN];
const int MOD = 998244353;

int rec(int idx,int sum){
    if(idx == n+1) return 0;

    int &ans = dp[idx][sum];

    if(ans != -1) return ans;

    ans = 0;

    ans = (ans + rec(idx+1,sum));

    int n_S = sum + a[idx];
    if(n_S < S) ans = (ans + rec(idx+1,n_S)%MOD)%MOD;
    if(n_S == S) ans = (ans + (n-idx+1)%MOD)%MOD; 

    return ans;
}

void solve(){
    cin>>n>>S;

    FOR(i,1,n) cin>>a[i];

    MINUS(dp);

    int ans = 0;
    FOR(i,1,n){
        ans = (ans + rec(i,0))%MOD;
    }
    cout<<ans<<endl;
}

signed main(){

   FastRead;    


    int t = 1; 
    // cin>>t; 
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}