#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define res(n) resize(n)
#define rev(v) reverse(v.begin(),v.end())
#define sor(v) sort(v.begin(),v.end())
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define ve vector
#define pq priority_queue
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;


template <typename T> T gcd(T a, T b) {if(b == 0) return a;return gcd(b,a%b);}
template <typename T> T extgcd(T a, T b, T& x, T& y){
    T d = a;
    if(b != 0){d = extgcd(b,a%b,y,x); y-=(a/b)*x;}
    else x=1,y=0;
    return d;
}
template <typename T> T modpow(T x, T n, T m) {
    if(n==0) return 1;
    T resp = modpow(x*x%m,n/2,mod);
    if(n&1) resp = resp*x%m;
    return resp;
}
template <typename T> T modinverse(T a, T m) {
    T x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
struct combination {
    ll M = mod;
    vector<ll> fact;vector<ll> ifact;
    combination(ll n):fact(n+1),ifact(n+1){
        fact[0]=1;ifact[0]=1;
        for (ll i = 0; i<n; i++) {fact[i+1] = fact[i]*(i+1) % M;ifact[i+1] = ifact[i]*modpow(i+1, M-2, M) % M;}
    }
    ll com(ll a, ll b){
        if(a == 0 && b == 0)return 1;if(a < b || a < 0)return 0;
        ll tmp = ifact[a-b]* ifact[b] % M;
        return tmp * fact[a] % M;
    }
};




int main()
{

    int N,M,K;
    cin >> N >> M >> K;
    ll ans = 0;
    ll n = (ll)N; ll m = (ll)M; ll k = (ll)K;
    
    combination C(n*m);
    ll A = C.com(n*m-2,k-2);
    ll b = 0;
    rep(i,M){
        ans += (ll)i*n*n*A*(ll)(M-i)%mod;
        ans %= mod;
    }
    rep(i,N){
        ans += (ll)i*m*m*A*(ll)(N-i)%mod;
        ans %= mod;
    }
    
    out(ans%mod);


    return 0;
}
