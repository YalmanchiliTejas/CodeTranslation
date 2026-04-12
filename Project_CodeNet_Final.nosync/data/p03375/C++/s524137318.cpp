#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

template <typename T>
T mod_expt(T a, std::int64_t n, T mod){
    T power {1};
    while(n > 0){
        if(n & 1){power = power * a % mod;}
        a = a * a % mod;
        n >>= 1;
    }
    return power;
}

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

    Combinatorics() = default;

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

Combinatorics<ll> comb;
int N, M;
ll dp[3100][3100];

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M;

    dp[0][0] = 1;

    for(int i=0;i<N;++i){
        for(int j=0;j<=N;++j){
            dp[i+1][j] = (dp[i+1][j] + dp[i][j] * (j + 1)) % M;
            dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % M;
        }
    }
    
    comb = Combinatorics<ll>(3100, M);

    ll res = 0;

    for(int i=1;i<=N;++i){
        int s = i % 2 == 1 ? +1 : M - 1;
        ll x = 0;

        for(int j=0;j<=i;++j){
            x = (x + dp[i][j] * mod_expt<ll>(2ll, (N - i) * j, M)) % M;
        }

        x = x * mod_expt<ll>(2ll, mod_expt<ll>(2ll, N - i, M - 1), M) % M * s % M * comb.nCk(N, i);
        
        res = (res + x) % M;
    }
    
    res = (mod_expt<ll>(2ll, mod_expt<ll>(2ll, N, M - 1), M) + M - res) % M;
    std::cout << res << std::endl;
}
