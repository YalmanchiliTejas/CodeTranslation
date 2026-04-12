#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

const ll MOD = 1e9+7;
 
template <ll MOD>
struct modint{
    ll x;
    modint() : x(0) {}
    modint(ll a): x((a % MOD + MOD) % MOD) {}
    
    
 
    bool operator!() const{return !x;}
 
    bool operator<(const modint &a) const{
        modint res(*this);
        return res.x < a.x;
    }
    
    bool operator>(const modint &a) const{
        modint res(*this);
        return res.x > a.x;
    }
 
    modint &operator+=(const modint &a){
        if((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
 
    modint &operator-=(const modint &a){
        if((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
 
    modint &operator*=(const modint &a){
        (x *= a.x) %= MOD;
        return *this;
    }
 
    modint &operator/=(const modint &a){
        *this *= a.inv();
        return *this;
    }
 
    modint &operator%=(const modint &a){
        x %= a.x;
        return *this;
    }
 
    modint operator-() const{ return modint(-x); }
 
    modint operator+(const modint &a) const{ return modint(*this) += a; }
    modint operator-(const modint &a) const{ return modint(*this) -= a; }
    modint operator*(const modint &a) const{ return modint(*this) *= a; }
    modint operator/(const modint &a) const{ return modint(*this) /= a; }
    modint operator%(const modint &a) const{ return modint(*this) %= a; }
    bool operator==(const modint &a) const{ return x == a.x; }
    bool operator!=(const modint &a) const{ return x != a.x; }
 
 
    modint pow(ll n) const{
        modint res(1), a(x);
        while(n > 0){
            if(n & 1) res *= a;
            a *= a;
            n /= 2;
        }
        return res;
    }
 
    modint inv() const{
        return this->pow(MOD-2);
    }
 
    friend ostream &operator<<(ostream &os, const modint &m){
        return os << m.x;
    }
 
    friend istream &operator>>(istream &is, modint &m){
        ll t;
        is >> t;
        m = modint<MOD>(t);
        return (is);
    }
    
    static ll get_mod(){ return MOD; }
};
using mint = modint<MOD>;

mint fact[200000];

mint combination(ll n, ll k){
    return fact[n]/fact[k]/fact[n-k];
}

int main(){
    fact[0] = 1; fact[1] = 1;
    rep(i,2,200000){
        fact[i] = (mint)i*fact[i-1];
    }

    ll n,m,k;
    cin >> n >> m >> k;

    mint memo1 = 0,memo2 = 0;

    rep(i,1,m){
        memo1 += i*(m - i)*n*n;
    }    
    memo1 *= combination(n*m-2,k-2);

    rep(i,1,n){
        memo2 += i*(n - i)*m*m;
    }    
    memo2 *= combination(n*m-2,k-2);

    mint ans = memo1 + memo2;

    cout << ans << endl;

}
