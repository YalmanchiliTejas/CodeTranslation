#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse4")
using namespace std;

# define mp make_pair
# define pb push_back
# define PI acos(-1)
# define ff first 
# define ss second 
# define endl '\n'
# define vt vector
# define all(c) (c).begin(), (c).end()
# define rep(i,a,b) for(ll i = a ; i < b ; ++i)

typedef long long ll ; 
typedef long double ld ; 
typedef pair<int,int> pii ; 
typedef pair<ll,ll> pll ;

template<class T> bool umin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int MOD = 998244353  ;
const ll inf = 1e18 ;  
const ll mod = 1e9+7 ;  
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T lcm(T a, T b) { return (a*b)/gcd(a,b) ; }
template<typename T> T power(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
ll nCr(ll n,ll r){ll t=1;if(r>n)return 0;if(r>n-r)r=n-r;for(ll i=0;i<r;i++){t*=(n-i);t/=(i+1);}return t;}

void read(vt<int> &a) {
    rep(i,0,a.size()) 
        cin >> a[i] ; 
}
void read(vt<ld> &a) {
    rep(i,0,a.size()) 
    cin >> a[i] ; 
}

bool prime(ll t) {
    for(ll i  =2 ; i*i <= t ; ++i) {
        if(t%i==0) 
            return 0 ; 
    }
    return 1 ; 
}
bool cmp(pii &a , pii &b) {
    if(a.ss == b.ss) 
        return a.ff > b.ff ; 
    return a.ss < b.ss ; 
}

// ==========Start Here==============



int main() 
{ 
    int n ;
    cin >> n ; 
    vt<ll> a(n); 
    rep(i,0,n) cin >> a[i] ;  
    ll sum= 0;
    vt<ll> sums(n) ;  
    rep(i,0,n){
        sum += a[i] ; 
        sum %= mod; 
        sums[i] = sum ; 
      //  cout << sums[i] << " " ; 
    }

    ll ans = 0 ; 
    rep(i,1,n) {
        ans += (sums[i-1]*a[i])%mod ;
        ans %= mod ;
    }
    cout << ans ; 


    return 0; 
} 