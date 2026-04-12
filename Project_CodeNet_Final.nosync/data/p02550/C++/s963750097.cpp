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
ll mx=2*1e5+7;
vector<VL> adj;
VL sub;
// VL igno;
ll n;

void dfs(ll r, ll parent){
    sub[r]=1;
    // if(igno[r]==1){return;}
    // debug(r,parent);
    for(auto k: adj[r]){
        if(k==parent){continue;}
        dfs(k, r);
        sub[r]+=sub[k];
    }
    return;
}

//It is not easy but it can be fun, if you think!!!

ll gcd(ll a, ll b){
    // debug(a,b);
    if(a>b){swap(a,b);}
    if(a==0){return b;}
    return gcd(a, b%a);
}
int centroid(ll u, ll p) {
    // debug(u,p);
    for (auto v : adj[u])
        if (v != p and sub[v] > n/2) return centroid(v, u);

    return u;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    #endif
    // ll tc,t;
    // cin>>tc;
    // while(tc--){
        ll n,x,m,k,i,j,o;
        // cin>>n;
        cin>>n>>x>>m;
        VL last(m, -1);
        ll ai=x;
        last[x%m]=0;
        ll st = 0, period = 0;
        VL l;
        l.pb(ai);
        FOR(i,m+1,1){
            ai = (ai*ai)%m;
            l.pb(ai);
            if(last[ai]!=-1){
                st = last[ai];
                period = i - last[ai];
                break;
            }
            last[ai]=i;
        }
        // debug(l,st,period);
        ll ans=0;
        FOR(i,st,0){
            ans+=l[i];
            n-=1;
            if(n==0){
                cout<<ans;
                exit(0);
            }
        }
        VL mp;
        ll sum_cycle = 0;
        FOR(i,st+period,st){
            sum_cycle+=l[i];
            mp.pb(sum_cycle);
        }
        ans+=(n/period)*sum_cycle;
        n = n-(period*(n/period));
        if(n>0){
            ans+=mp[n-1];
        }
        cout<<ans;




    // }
}