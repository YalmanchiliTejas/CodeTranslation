#include <bits/stdc++.h>
using namespace std;
#define X ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FIXED_FLOAT(x) std::fixed <<std::setprecision(2)<<(x)
 
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
// long long p = 1e9+7;
 
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<int> VI;
typedef vector<pair<ll,ll>> VP;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<bool> VB;
 
// typedef pair<ll, ll> PL;
typedef unordered_map<ll, ll> UMP;
#define FOR(i,b,init) for(i=init;i<b;i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
 
// typedef  unordered_set<ll>;
 
 
// void printa(VI &x,ll n){
//     ll i;
//     FOR(i, n){
//         cout<<x[i]<<" ";
//     }
//     cout<<endl;
// }
 
 

/////GLOABLS VARS
ll MOD = 1e9+7;
ll gmx = 1e6+7; 

VL fact(gmx, 1);
//////FUNCTIONS
ll powp(ll val, ll deg)
{
    // debug(val, deg);
    if (!deg)
        return 1;
    if (deg & 1)
        return (powp(val, deg - 1) * val) % MOD;
    ll res = powp(val, deg >> 1);
    // debug(res);
    return (res * res) % MOD;
}
ll mx=1e5+7;
vector<VL> adj;
VL sub;
ll n;

void dfs(ll r, ll parent){
    sub[r]=1;
    // debug(r,parent);
    for(auto k: adj[r]){
        if(k==parent){continue;}
        dfs(k, r);
        sub[r]+=sub[k];
    }
    return;
}

//It is not easy but it can be fun, if you think!!!

//
// ll mx = 2*1e5+7;
// vector<vector<pl>> adj;
//dp[i] =(k-1)*dp[i-1]
// (k-1)**(n-2)-(k-1)**(n-3)
//

long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.


}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    #endif

    ll n,i,j;
    cin>>n;
    VL l(n), pre(n);
    FOR(i,n,0){
        cin>>l[i];
    }
    pre[n-1] = l[n-1];
    FOR(i,n,1){
        pre[n-1-i]+=pre[n-i]+l[n-i-1];
        pre[n-1-i]%=MOD;
    }
    // debug(l, pre);
    ll ans=0;
    FOR(i,n-1,0){
        ans+= (l[i]*(pre[i+1]))%MOD;
        ans %= MOD;
    }
    cout<<ans;

    // 1 3 1
    // cin>>t;
    // FOR(i,t,0){
    //     ll n;
    //     cin>>n;
        
    // }


   
}
