/*created by tanishk gupta*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define repl(i,a,n) for(long long int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef vector<int> VI;
typedef long long int ll;
typedef unsigned long long ull;
//typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll MOD=1e9+7;
const ll mod=1e9+7;
//const llint MOD;
const ll N=(ll)(1e6+1);
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll add(ll a,ll b){return ((a%MOD)+(b%MOD))%MOD;}
ll mul(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}
ll sub(ll a,ll b){return ((a%MOD)-(b%MOD)+MOD)%MOD;}
ll binpow(ll x, ll y){ll z = 1;while(y){if(y & 1) z = mul(z, x);x = mul(x, x);y >>= 1;}return z;}
ll inv(int x){return binpow(x, MOD - 2);}
ll divide(ll x, ll y){return mul(x, inv(y));}
ll fact[N];
void precalc(){fact[0] = 1;for(ll i = 1; i < N; i++)fact[i] = mul(fact[i - 1], i);}
ll C(ll n, ll k){return divide(fact[n], mul(fact[k], fact[n - k]));}
//bool prime[N];
//void sieve() {for(int i=2;i<N;i++) {prime[i]=true;}for (int p=2; p*p<=N; p++){if (prime[p] == true){for (int i=p*p; i<=N; i += p)prime[i] = false;}}}
ll legendpow(ll n, ll p){ll total = 0;while (n){n /= p;total += n;}return total;}

//head==================================================================================
/*I adj[200005];
int vis[200005];
int tot=0;
void dfs(int node)
{
    tot++;
    vis[node]=1;
    for (auto x : adj[node])
    {
        if (vis[x]==0)
        {
            dfs(x);
        }
    }
}*/


int main()
{

    int n;
    cin>>n;
    ll a[n];
    ll sum=0;
    rep(i,0,n){cin>>a[i];
    sum+=a[i];}
    ll p=mul(sum,sum);
    rep(i,0,n)
    {
        p=sub(p,mul(a[i],a[i]));
    }
    p=divide(p,2);
    cout<<p;
}
