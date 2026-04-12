#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

ll N, X;
ll dp1[51], dp2[51];

ll f(ll n, ll x){
    if(n == 0){
        return 1;
    }

    if(x == 1){
        return 0;
    }else if(x <= dp1[n-1] + 1){
        return f(n - 1, x - 1);
    }else if(x == dp1[n-1] + 2){
        return 1ll + dp2[n-1];
    }else if(x <= 2ll * dp1[n-1] + 2){
        return f(n - 1, x - dp1[n-1] - 2) + 1 + dp2[n-1];
    }
    return 2ll * dp2[n-1] + 1;
}

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    dp1[0] = 1; // 層数
    dp2[0] = 1; // パティの個数

    for(int i=1;i<=50;++i){
        dp1[i] = 2ll * dp1[i-1] + 3;
        dp2[i] = 2ll * dp2[i-1] + 1;
    }

    std::cin >> N >> X;

    ll res = f(N, X);
    std::cout << res << std::endl;
}
