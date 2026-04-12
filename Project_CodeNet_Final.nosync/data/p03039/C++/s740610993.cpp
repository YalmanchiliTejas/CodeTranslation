#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

template <typename T>
std::tuple<T, T, T> extgcd(T a, T b){
    T s1 = 1, t1 = 0, s2 = 0, t2 = 1;
    while(b != 0){
        std::tie(s1, t1, s2, t2) = std::make_tuple(s2, t2, s1 - (a / b) * s2, t1 - (a / b) * t2);
        std::tie(a, b) = std::make_tuple(b, a % b);
    }
    return std::make_tuple(s1, t1, a);
}

// 注意: a と mod が互いに素である必要がある
template <typename T>
T mod_inverse(T a, T mod){
    T b;
    std::tie(b, std::ignore, std::ignore) = extgcd(a, mod);
    if(b < 0){b += mod;}
    return b;
}

template <typename T>
struct Combinatorics{
    T modulo;
    std::vector<T> fact, inv_fact;

    Combinatorics(T max, T modulo) : modulo(modulo), fact(max + 1), inv_fact(max + 1) {
        fact[0] = 1;
        for(T i=1;i<=max;++i){
            fact[i] = i * fact[i - 1] % modulo;
        }

        inv_fact[max] = mod_inverse(fact[max], modulo);
        for(T i=max;i>0;--i){
            inv_fact[i - 1] = i * inv_fact[i] % modulo;
        }
    }

    T nPk(T n, T k){
        if(n < k){return 0;}
        return fact[n] * inv_fact[n - k] % modulo;
    }

    T nCk(T n, T k){
        if(n < k){return 0;}
        return fact[n] * inv_fact[k] % modulo * inv_fact[n - k] % modulo;
    }

    T nHk(T n, T k){
        if(n == 0 && k == 0){return 1;}
        return nCk(n + k - 1, k);
    }
};

constexpr ll MOD = 1'000'000'007;
Combinatorics<ll> comb(400100, MOD);
ll N, M, K;

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M >> K;

    ll r1 = 0, r2 = 0;

    for(int d=1;d<N;++d){
        r1 = (r1 + 1ll * d * (N - d)) % MOD;
    }

    r1 = r1 * M % MOD * M % MOD * comb.nCk(N * M - 2, K - 2) % MOD;

    for(int d=1;d<M;++d){
        r2 = (r2 + 1ll * d * (M - d)) % MOD;
    }

    r2 = r2 * N % MOD * N % MOD * comb.nCk(N * M - 2, K - 2) % MOD;

    ll res = (r1 + r2) % MOD;

    std::cout << res << std::endl;
}