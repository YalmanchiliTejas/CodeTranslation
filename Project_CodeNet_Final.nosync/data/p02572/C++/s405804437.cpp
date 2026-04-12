#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

struct mint{
    static const long long MOD = 1000000007;

    long long v;

    mint() : v(0) {}
    mint(long long x){
        x = x % MOD;
        if(x < 0){ x += MOD; }
        v = x;
    }
    mint& operator+=(mint a){
        v += a.v;
        if(v >= MOD){ v -= MOD; }
        return *this;
    }
    mint& operator*=(mint a){
        v *= a.v;
        v %= MOD;
        return *this;
    }
    mint& operator-=(mint a){
        v -= a.v;
        if(v < 0){ v += MOD; }
        return *this;
    }
    mint& operator/=(mint a){
        return (*this) *= a.inv();
    }

    mint operator*(mint a) const{
        return mint(v) *= a;
    }

    mint operator+(mint a) const {
        return mint(v) += a;
    }

    mint operator-(mint a) const {
        return mint(v) -= a;
    }

    mint operator/(mint a) const {
        return mint(v) /= a;
    }

    mint pow(long long k) const {
        mint res(1),tmp(v);
        while(k){
            if(k&1) res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }
    mint inv(){return pow(MOD - 2); }

    static mint comb(long long n, int k){
        mint res(1);
        for(int i = 0; i < k; ++i){
            res *= mint(n - i);
            res /= mint(i + 1);
        }
        return res;
    }

    static mint factorial(long long n){
        mint res(1);
        for(int i = n; i > 1; --i){
            res *= mint(i);
        }
        return res;
    }

    bool operator<(const mint &a) const {
        return v < a.v;
    };
};

mint operator*(long long l, mint r){ return r * l; }

std::ostream& operator<<(std::ostream& stream, const mint& m){
    stream << m.v;
    return stream;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n){ cin >> a.at(i); }

    mint ans = 0;
    mint cs = 0;
    REP(i, n){
        ans += cs * a.at(i);
        cs += a.at(i);
    }
    cout << ans << endl;
    return 0;
}
