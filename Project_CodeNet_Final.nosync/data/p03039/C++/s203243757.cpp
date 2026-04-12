#include <bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long MOD = 1000000007;
    unsigned long N, M, K;
    cin >> N >> M >> K;
    unsigned long NN = N * N % MOD, MM = M * M % MOD;
    unsigned long d{(N * (MM * (NN - 1)) % MOD + M * (NN * (MM - 1)) % MOD) % MOD}, n{6};
    K -= 2;
    auto NM = N * M - 2;
    for(unsigned long i = 0, j = NM - K; i != K;){
        (d *= ++j) %= MOD;
        (n *= ++i) %= MOD;
    }
    auto p = MOD - 2;
    while(p){
        if(p & 1)(d *= n) %= MOD;
        (n *= n) %= MOD;
        p >>= 1;
    }
    cout << d << endl;
    return 0;
}