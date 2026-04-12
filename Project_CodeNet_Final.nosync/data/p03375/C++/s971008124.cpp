#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
using namespace std;

long long N, MOD;

long long bipow(long long n, long long m, long long mod) {
    if (m == 0) return 1;
    if (m % 2 == 0) {
        n = (n * n) % mod;
        return bipow(n, m / 2, mod) % mod;
    } else
        return (n * bipow(n, m - 1, mod)) % mod;
}

// Combination
class Comb{
    vector<long long> fact_num, fact_den;
public:
    Comb(int N){
        fact_num.resize(N+1, 0);
        fact_den.resize(N+1, 0);
        vector<long long> fact_denpow(N+1, 0);

        fact_num[0] = 1;
        for(int i=1; i<=N; i++) fact_num[i] = (fact_num[i-1] * i) % MOD;

        for(int i=0; i<=N; i++) fact_denpow[i] = bipow(i, MOD-2, MOD);
        fact_den[0] = 1;
        for(int i=1; i<=N; i++) fact_den[i] = (fact_den[i-1] * fact_denpow[i]) % MOD;
    }
    long long calc(int m, int n){
        assert(m >= n);
        return ((fact_num[m] * fact_den[n]) % MOD * fact_den[m-n]) % MOD;
    }
};

long long dp[3333][3333];

int main(){
    cin >> N >> MOD;
    Comb comb(N);

    for(int i=0; i<=3000; i++)
        dp[i][0] = 1;

    for(int i=1; i<=3000; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = (dp[i-1][j-1] + ((j+1)*dp[i-1][j]) % MOD) % MOD;
        }
    }

    long long ans = 0;
    for(int i=0; i<=N; i++){
        long long tmp = 0;
        for(int j=0; j<=i; j++){
            tmp += (dp[i][j] * bipow(2, (N-i)*j, MOD)) % MOD;
            tmp %= MOD;
        }
        tmp = (tmp * bipow(2, bipow(2, N-i, MOD-1), MOD)) % MOD;
        tmp = (tmp * comb.calc(N, i)) % MOD;
        if(i % 2)
            tmp = (MOD - tmp) % MOD;
        ans = (ans + tmp) % MOD;
    }
    cout << ans << endl;
    return 0;
}