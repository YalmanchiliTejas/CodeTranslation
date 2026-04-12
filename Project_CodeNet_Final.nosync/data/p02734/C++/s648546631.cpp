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

template<typename T>
struct NDVector{
    vector<ll> dim;
    vector<ll> mul;
    vector<T> value;

    size_t convert_index(initializer_list<ll> idx) const {
        size_t ret = 0;
        ll i = 0;
        for(auto it = idx.begin(); it != idx.end(); ++it){
            ret += (*it) * mul.at(i);
            i++;
        }
        return ret;
    }

    void reset_mul(){
        mul.resize(dim.size());
        mul.at(0) = 1;
        for(ll i = 1; i < dim.size(); ++i){
            mul.at(i) = mul.at(i - 1) * dim.at(i - 1);
        }
    }

    NDVector(){}

    NDVector(T init, initializer_list<ll> dim_) : dim(dim_) {
        size_t total = 1;
        for(size_t d : dim){
            total *= d;
        }
        value.resize(total, init);
        reset_mul();
    }

    void resize(initializer_list<ll> new_dim){
        dim.resize(new_dim.size());
        copy(new_dim.begin(), new_dim.end(), dim.begin());
        ll total = 1;
        for(ll d : dim){
            total *= d;
        }
        value.resize(total);
        reset_mul();
    }

    void fill(const T& v){
        std::fill(value.begin(), value.end(), v);
    }

    typename vector<T>::const_reference at(initializer_list<ll> idx) const {
        return value.at(convert_index(idx));
    }

    typename vector<T>::reference at(initializer_list<ll> idx){
        return value.at(convert_index(idx));
    }
};

vector<long long> A;
NDVector<mint> cache;
NDVector<bool> flg;

mint calc(ll pos, ll rest, ll state){
    if(rest == 0){
        return static_cast<ll>(A.size()) - pos + 1;
    }
    if(pos >= A.size() || rest < 0){
        return 0;
    }
    if(flg.at({pos, rest, state})){
        return cache.at({pos, rest, state});
    }

    mint ret = 0;
    if(state == 0){
        ret += calc(pos + 1, rest - A.at(pos), 1) * (pos + 1);
    }else{
        ret += calc(pos + 1, rest - A.at(pos), 1);
    }
    ret += calc(pos + 1, rest, state);

    flg.at({pos, rest, state}) = true;
    cache.at({pos, rest, state}) = ret;
    return ret;
}

void solve(long long N, long long S){
    cache.resize({N, S + 1, 2});
    flg.resize({N, S + 1, 2});
    flg.fill(false);
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
