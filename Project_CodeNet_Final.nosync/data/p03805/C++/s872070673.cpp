# include <bits/stdc++.h>
# define ll int64_t
# define rep(i,n) for(ll i=0;i<n;i++)
# define rrep(i,n) for(ll i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mod 1000000007
# define vec vector
#define dump(x) cerr<<#x<<"="<<x<<endl
#define Array vec<ll>
using namespace std;

bool compare_by_b(pair<string,ll> a,pair<string,ll> b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

bool my_compare(pair<string,ll> a,pair<string,ll> b){
    
    if(a.first != b.first) return a.first<b.first;
    if(a.second != b.second) return a.second>b.second;
    else return true;
}

ll factorial(ll n){
    ll x=1;
    rrep(i,n) (x*=i)%=mod;
    return x;
}

ll gcd(ll a,ll b)
{
   if (a%b == 0) return(b);
   else return(gcd(b,a%b));
}

ll lcm(ll a,ll b)
{
   return a/gcd(a,b)*b;
}

//累乗だってさ
ll modpow(ll a,ll n,ll mod1) {
    ll res=1;
    while(n>0){
        if(n&1) res=res*a%mod1;
        a = a*a%mod1;
        n >>= 1;
    }
    return res;
}

ll combination(ll n,ll r){
    ll sum=1;
    rrep(i,min(r,n-r)) (sum*=(n-i+1))%=mod;
    return sum;
}

//逆元だってさ
ll modinv(ll a,ll mod1) {
    return modpow(a, mod1 - 2, mod1);
}

ll n,m,ans=0;

void dfs(vec<vec<ll>>& g, ll v,Array order) {
    order.pb(v);
    if (order.size() == n) {
        ans++;
        return;
    }
    for (auto next : g[v]) {
        bool flag = false;
        for (auto i : order) if (i == next) flag = true;
        if (flag) continue;
        dfs(g, next, order);
    }
}

void solve(){
    cin>>n>>m;
    vec<vec<ll>> g(n);
    rep(i,m){
        ll a,b;
        cin>>a>>b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
        Array order;
        dfs(g,0,order);
        cout<<ans<<endl;
    
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    
    return 0;
}
