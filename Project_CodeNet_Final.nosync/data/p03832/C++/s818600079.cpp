#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <set>
#include <cmath>
using namespace std;
#define MOD 1000000007

long long dp[1001][1001];

// 繰り返し二乗法
long long bipow(long long n, int m) {
    if (m == 0) return 1;
    if (m % 2 == 0) {
        n = (n * n) % MOD;
        return bipow(n, m / 2) % MOD;
    } else
        return (n * bipow(n, m - 1)) % MOD;
}

// fact_num[i] = i! % MOD
// fact_denpow[i] = (i**(MOD-2)) % MOD
// fact_den[i] = fact_denpow[i]! % MOD
// nCm = fact_num[n] * fact_den[m] * fact_den[n-m]
// で計算できる（MODを適切に取る）
// O(NlogN)
void set_table(int N, vector<long long> &fact_num, vector<long long> &fact_den){
    fact_num.resize(N+1, 0);
    fact_den.resize(N+1, 0);
    vector<long long> fact_denpow(N+1, 0);

    fact_num[0] = 1;
    for(int i=1; i<=N; i++) fact_num[i] = (fact_num[i-1] * i) % MOD;

    for(int i=0; i<=N; i++) fact_denpow[i] = bipow(i, MOD-2);
    fact_den[0] = 1;
    for(int i=1; i<=N; i++) fact_den[i] = (fact_den[i-1] * fact_denpow[i]) % MOD;
}

// mCn
long long comb(const vector<long long> &fact_num, const vector<long long> &fact_den, int m, int n){
    return ((fact_num[m] * fact_den[n]) % MOD * fact_den[m-n]) % MOD;
}

int main(){
    long long N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    vector<long long> fact_num, fact_den;
    set_table(N, fact_num, fact_den);

    dp[A-1][N] = 1;
    for(int i=A; i<=B; i++){
        for(int j=0; j<=N; j++)
            dp[i][j] = dp[i-1][j];

        for(int j=1; j<=N; j++){
            if(j - C*i < 0) continue;
            long long c = 1;
            long long cur = j;
            for(int k=1; k<C; k++){
                c = (c * comb(fact_num, fact_den, cur, i)) % MOD;
                cur -= i;
            }
            for(int k=C; k<=D; k++){
                c = (c * comb(fact_num, fact_den, cur, i)) % MOD;
                cur -= i;
                if(cur < 0) break;
                dp[i][cur] += (dp[i-1][j] * ((c * fact_den[k]) % MOD)) % MOD;
                dp[i][cur] %= MOD;
            }
        }
    }
    cout << dp[B][0] << endl;

    return 0;
}
