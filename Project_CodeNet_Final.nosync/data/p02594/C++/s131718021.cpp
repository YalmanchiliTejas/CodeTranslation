#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll,ll> 
#define mll map<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0; i<n; i++)
#define All(x,v) for(auto x:v)
#define arrin(a,n) ll a[n]; rep(i,n) cin>>a[i]
#define vi vector<int>
#define nl "\n"
#define print(arr) All(x,arr) cout<<x<<" "; cout<<nl
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define ing(m,ad) rep(i,m){ int u,v; cin>>u>>v; u--;v--; ad[u].pb(v); ad[v].pb(u);}
#define vdsort(v) sort(v.begin(),v.end(),greater<int>())
#define F first
#define S second
#define mod 1000000007
const int MAXN=100005;
int spf[MAXN];
ll fac1[MAXN],fac2[MAXN],inv[MAXN];
ll gcd(ll x, ll y){ return y?gcd(y,x%y):x; }

void sieve(){  
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)  spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++) { 
        if (spf[i] == i) 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j)  spf[j] = i; 
    } 
} 
vector<int> getFactorization(int x){
    vector<int> ret; 
    while (x != 1) { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}

ll exp(ll n, ll m){
    ll a = 1;
    while (m){
        if (m & 1) a = (a * n % mod) % mod;
        m /= 2;
        n = (n*n) % mod;
    }
    return a;
}

void pre(){
    fac1[0]=fac2[0]=inv[1]=1;
    for(int i=1;i<MAXN;i++){
        fac1[i]=(fac1[i-1]*i)%mod;
        if(i>1) inv[i]=( mod - ((ll)(mod/i)*inv[mod%i])%mod ) %mod;
    }
    for(int i=1;i<MAXN;i++) fac2[i]=(fac2[i-1]*inv[i])%mod;
}
ll C(int n,int k){
    if(n<k) return 0;
    return ((fac1[n]*fac2[n-k]%mod)*fac2[k]%mod);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int n,t=1;
    // cin>>t;
    while(t--){
        cin>>n;
        if(n>=30) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}