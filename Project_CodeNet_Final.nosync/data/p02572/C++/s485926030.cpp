#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const ull mod = 1e9+7;
struct mint
{
    ll x;
    mint(ll x=0) : x((x%mod+mod)%mod){}
    mint operator-() const {return mint(-x);}
    mint& operator+=(const mint a){
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a){
        if((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a){
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if(!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if(t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}

    friend istream& operator>>(istream& is, mint& a) { return is >> a.x;}
    friend ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
};

int main(){
    const ull mod = 1e9+7;
    int n; cin >> n;
    ull a[n]; rep(i, n) cin >> a[i];

    mint sqsum(0);
    rep(i, n){
        mint tmp(a[i]);
        tmp *= a[i];
        sqsum += tmp;
    }

    mint sum(0);
    rep(i, n){
        mint tmp(a[i]);
        sum += tmp;
    }

    mint ans(1);
    ans *= sum;
    ans *= sum;
    ans -= sqsum;
    ans /= 2;
    cout << ans << endl;

    return 0;
}