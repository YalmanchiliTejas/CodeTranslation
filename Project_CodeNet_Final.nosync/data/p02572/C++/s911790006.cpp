#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

constexpr ll MOD = 1'000'000'007;
int N;
ll A[200100];

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N;

    for(int i=0;i<N;++i){
        std::cin >> A[i];
    }

    ll sum = 0, squareSum = 0;

    for(int i=0;i<N;++i){
        sum = (sum + A[i]) % MOD;
        squareSum = (squareSum + A[i] * A[i] % MOD) % MOD;
    }

    ll res = (sum * sum % MOD + MOD - squareSum) % MOD * ((MOD + 1) / 2) % MOD;
    std::cout << res << std::endl;
}
