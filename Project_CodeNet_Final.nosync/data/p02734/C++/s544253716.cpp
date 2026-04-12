#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

struct mint{
    static const long long MOD = 998244353;

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

vector<long long> A;
array<array<array<mint, 2>, 3001>, 3001> cache;
array<array<array<bool, 2>, 3001>, 3001> flg;

mint calc(ll pos, ll rest, ll state){
    if(rest == 0){
        return static_cast<ll>(A.size()) - pos + 1;
    }
    if(pos >= A.size()){
        return 0;
    }
    if(rest < 0){ return 0; }
    if(flg.at(pos).at(rest).at(state)){
        return cache.at(pos).at(rest).at(state);
    }

    mint ret = 0;
    if(state == 0){
        ret += calc(pos + 1, rest - A.at(pos), 1) * (pos + 1);
    }else{
        ret += calc(pos + 1, rest - A.at(pos), 1);
    }
    ret += calc(pos + 1, rest, state);

    flg.at(pos).at(rest).at(state) = true;
    cache.at(pos).at(rest).at(state) = ret;
    return ret;
}

void solve(long long N, long long S){
    REP(i, N + 1){
        REP(j, 3001){
            flg.at(i).at(j).at(0) = false;
            flg.at(i).at(j).at(1) = false;
        }
    }
    cout << calc(0, S, 0) << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long S;
    scanf("%lld",&S);
    A.resize(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, S);
    return 0;
}
