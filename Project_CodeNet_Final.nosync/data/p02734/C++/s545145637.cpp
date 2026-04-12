#include<bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long MOD = 998244353;
    unsigned long N, S;
    cin >> N >> S;
    unsigned long ans{0};
    vector<unsigned long> dp(S);
    for(unsigned long i{0}, A; i < N; ++i){
        cin >> A;
        if(A < S){
            ans += dp[S - A] * (N - i) % MOD;
            for(unsigned long j{S}; j --> A; )(dp[j] += dp[j - A]) %= MOD;
            (dp[A] += i + 1) %= MOD;
        }else if(A == S)ans += (i + 1) * (N - i) % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}