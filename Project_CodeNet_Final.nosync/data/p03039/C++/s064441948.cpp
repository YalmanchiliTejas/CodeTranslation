#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;


template <typename T> T gcd(T a, T b) {if(b == 0) return a;return gcd(b,a%b);}
template <typename T> T lcm(T a, T b) {return a*b/gcd(a,b);}
template <typename T> T extgcd(T a, T b, T& x, T& y){
    T d = a;
    if(b != 0){
        d = extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else x=1,y=0;
    return d;
}
template <typename T> T modpow(T x, T n, T m) {
    if(n==0) return 1;
    T resp = modpow(x*x%m,n/2,m);
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
    vector<ll> fact,ifact;
    combination(ll n):fact(n+1),ifact(n+1){
        fact[0]=1;ifact[0]=1;
        for (ll i = 0; i<n; i++) {
            fact[i+1] = fact[i]*(i+1) % M;
            ifact[i+1] = ifact[i]*modpow(i+1, M-2, M) % M;
        }
    }
    ll com(ll a, ll b){
        if(a == 0 && b == 0)return 1;
        if(a < b || a < 0)return 0;
        ll tmp = ifact[a-b] * ifact[b] % M;
        return tmp * fact[a] % M;
    }
};



int main()
{

    ll N,M,K;
    cin >> N >> M >> K;
    
    combination C(N*M);
    ll cc = C.com(N*M-2,K-2);
    
    ll ans = 0;
    
    for (ll i = 1; i <= M-1; i++) {
        ans += (cc*N*N%mod)*i*(M-i)%mod;
        ans %= mod;
    }
    for (ll i = 1; i <= N-1; i++) {
        ans += (cc*M*M%mod)*i*(N-i)%mod;
        ans %= mod;
    }
    cout << ans << endl;
    

    return 0;
}
