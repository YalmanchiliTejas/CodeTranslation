#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

int N;
ll A[200100], B[200100];
ll dp[200100];

ll rec(int i, bool odd){
    if(i == N - 1){
        return odd ? 0 : A[N-1];
    }

    if(i >= N){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    if(odd){
        dp[i] = std::max({B[i+2], A[i] + rec(i + 2, 1), A[i+1] + rec(i + 3, 0)});
    }else{
        dp[i] = std::max(A[i] + rec(i + 2, 0), B[i+1]);
    }

    return dp[i];
}

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for(int i=0;i<N;++i){
        std::cin >> A[i];
    }

    for(int i=N-1;i>=0;--i){
        B[i] = A[i] + B[i+2];
    }

    memset(dp, -1, sizeof(dp));

    ll res = rec(0, N % 2);
    std::cout << res << std::endl;
}
