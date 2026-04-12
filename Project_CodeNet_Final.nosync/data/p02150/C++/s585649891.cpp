#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

constexpr ll MOD = 1'000'000'007;
ll A, B, X;

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> A >> B >> X;

    ll res;

    if(X < A){
        res = X % MOD;
    }else{
        res = (X % MOD + (X - B) / (A - B) % MOD * (B % MOD) % MOD) % MOD;
    }

    std::cout << res << std::endl;
}

