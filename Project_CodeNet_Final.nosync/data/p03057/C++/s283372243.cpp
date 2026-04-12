#include<bits/stdc++.h>
using namespace std;

int main(){
    constexpr unsigned long MOD = 1000000007;
    unsigned long N, M;
    string s;
    cin >> N >> M >> s;

    if(equal(s.begin(), s.end() - 1, s.begin() + 1)){
        vector<unsigned long> fib(N + 1);
        fib[0] = 1;
        fib[1] = 1;
        for(unsigned long i = 2; i <= N; ++i){
            fib[i] = fib[i - 1] + fib[i - 2] % MOD;
        }
        cout << (fib[N - 2] + fib[N]) % MOD << endl;
    }else{
        if(N & 1)return 0 & puts("0");
        auto t = find(s.begin(), s.end(), 'R' ^ 'B' ^ s[0]) - s.begin();
        auto k = t | 1UL;
        {
            unsigned long cnt{0};
            for(auto &i : s){
                if(i == s[0])++cnt;
                else{
                    if(cnt & 1)k = min(k, cnt);
                    cnt = 0;
                }
            }
        }
        vector<unsigned long> dp(N + 1), sum(N + 1);
        dp[0] = 1;
        dp[1] = 1;
        sum[0] = 1;
        sum[1] = 1;
        for(unsigned long i = 2; i <= N; ++i){
            dp[i] = sum[i - 2];
            if(i > k + 2)dp[i] += MOD - sum[i - k - 3];
            (sum[i] = sum[i - 2] + (dp[i] %= MOD)) %= MOD;
        }
        unsigned long ans{0};
        for(unsigned long l = 1; l <= k; l += 2)(ans += (l + 1) * dp[N - l - 1] % MOD) %= MOD;
        cout << ans % MOD << endl;
    }
    return 0;
}