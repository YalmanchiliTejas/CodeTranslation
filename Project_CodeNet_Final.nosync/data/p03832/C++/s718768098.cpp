#include <bits/stdc++.h>

using namespace std;

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)

using ll = long long;
using P = std::tuple<int,int>;

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

const ll MOD = 1e9 + 7;
ll N, A, B, C, D;
ll dp[1010][1010];


namespace tottori{
    // until C++17
    template <typename T, size_t N>
    constexpr size_t size(const T (&array)[N]){
        return N;
    }
};

template <typename T>
T expt(T a, T n, T mod = std::numeric_limits<T>::max()){
    T res = 1;
    while(n){
        if(n & 1){res = res * a % mod;}
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

template <typename T>
T inverse(T n, T mod){
    return expt(n, mod-2, mod);
}

ll fact[3000], inv[3000];

// nPr
template <typename T>
T nPr(T n, T r, T mod = std::numeric_limits<T>::max()){
    if(n < r){return 0;}
    return fact[n] * inv[n-r] % mod;
}

// nCk
template <typename T>
T nCk(T n, T k, T mod = std::numeric_limits<T>::max()){
    if(n < k){return 0;}
    return fact[n] * inv[k] % mod * inv[n-k] % mod;
}

template <typename T>
T nHk(T n, T k, T mod = std::numeric_limits<T>::max()){
    if(n == 0 && k == 0){return 1;}
    return nCk(n+k-1, k);
}

void initFactAndInv(ll mod){
    fact[0] = 1;
    inv[0] = 1;
    
    for(int i=1;i<tottori::size(fact);i++){
        fact[i] = fact[i-1] * i % mod;
        inv[i] = inverse(fact[i], mod);
    }
}

ll rec(int n, int i){
    if(dp[n][i] != -1){return dp[n][i];}
    if(n == 0){return 1ll;}
    if(n < i || B < i){return 0ll;}
    
    ll res = rec(n, i+1);
    
    for(int j=C;j<=D;++j){
        if(i * j > n){break;}

        // printf("%d, %d, %d: %lld, %lld\n",
        //        n, i, j,
        //        rec(n-i*j, i+1),
        //        nPr(1ll * n, 1ll * i*j, MOD) * inverse(expt(fact[i], 1ll * j, MOD), MOD) % MOD * inverse(fact[j], MOD) % MOD * rec(n-i*j, i+1) % MOD);
        // printf("%d, %d, %d: (%lld, %lld, %lld)\n",
        //        n, i, j,
        //        nPr(1ll * n, 1ll * i*j, MOD),
        //        expt(fact[i], 1ll * j, MOD),
        //        fact[j]);
        res = (res + nPr(1ll * n, 1ll * i*j, MOD) * expt(inv[i], 1ll * j, MOD) % MOD * inv[j] % MOD * rec(n-i*j, i+1) % MOD) % MOD;
    }

    // printf("%d, %d: %lld\n", n, i, res);
    return dp[n][i] = res;
}

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    initFactAndInv(MOD);
    
    std::cin >> N >> A >> B >> C >> D;

    memset(dp, -1ll, sizeof(dp));
    
    std::cout << rec(N, A) << std::endl;
}
