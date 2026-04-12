#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

#define endl '\n'
#define loop(i, m, n) for (ll i = m; i < n; i++)
#define loope(i, m, n) for (ll i = m; i <= n; i++)
#define epool(i, m, n) for (ll i = m; i >= n; i--)
#define mod 1000000007
#define mod2 998244353                                                                          
#define vi vector<ll>
#define pll pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define MP make_pair
#define empf emplace_front
#define empb emplace_back
#define ret(x) return cout << x,0;
#define all(v) v.begin(),v.end() 
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll,vector<ll>,greater<ll>>
const ll INF=1e18;
const double PI=4*atan(1);

#define SpeedForce               \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                    \
    cout.tie(0);

using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

const int maxN=8*1e6;
bool prime[maxN+1];
ll mpow(ll base,ll exp);
ll POW(ll base,ll exp);
ll gcd(ll a,ll b);
ll modInverse(ll n);
ll nCr(ll n, ll r);
void sieve();
ll myxor(ll a,ll b);

int dx[]={-1,0,1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};

void solve(){
    ll n;
    cin >> n;
    vi a(n);
    loop(i,0,n) cin >> a[i];

    vi p(n);
    p[0]=a[0];
    loop(i,1,n){
        p[i]=p[i-1]+a[i];
        p[i]%=mod;
    }
    ll ans=0;
    for(int i=n-1;i>=1;i--){
        p[i-1]%=mod;
        ans+=a[i]*p[i-1];
        ans%=mod;
    }

    cout << ans << endl;

}

int32_t main(){
    SpeedForce


    int t;
    t=1;
    //cin >> t;
    cerr << endl;
    while (t--){
        //cout << fixed << setprecision(10);
        solve();
    }
    cerr << "Time : " << 1000*((double)clock())/ (double)CLOCKS_PER_SEC << "ms" << endl;
}   

ll POW(ll base,ll exp){
    ll result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((ll)result * base);
        base = ((ll)base * base);
        exp >>= 1;
    }
    return result;
}

ll mpow(ll base, ll exp){
    base %= mod;
    ll result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

ll modInverse(ll n) { 
    return mpow(n, mod-2); 
}
 
ll nCr(ll n, ll r){ 
   if (r==0) 
      return 1; 
    ll fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = (fac[i-1]*i)%mod; 
    return ((fac[n]* modInverse(fac[r]) % mod * 
            modInverse(fac[n-r]) % mod)%mod)%mod; 
}

ll myxor(ll a,ll b){
    return (a|b)&(~a|~b);
}

void sieve(){
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<maxN;p++){
        if(prime[p]){
            for(int i=2*p;i<maxN;i+=p){
                prime[i]=false;
            }
        }
    }
}