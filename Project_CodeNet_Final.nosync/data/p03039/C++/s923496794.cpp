#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define MOD 1000000007

long long bipow(long long n, long long m) {
    if (m == 0) return 1;
    if (m % 2 == 0) {
        n = (n * n) % MOD;
        return bipow(n, m / 2) % MOD;
    } else
        return (n * bipow(n, m - 1)) % MOD;
}

vector<long long> fact_num, fact_den;

void set_table(long long N, vector<long long> &fact_num, vector<long long> &fact_den){
    fact_num.resize(N+1, 0);
    fact_den.resize(N+1, 0);
    vector<long long> fact_denpow(N+1, 0);

    fact_num[0] = 1;
    for(long long i=1; i<=N; i++) fact_num[i] = (fact_num[i-1] * i) % MOD;

    for(long long i=0; i<=N; i++) fact_denpow[i] = bipow(i, MOD-2);
    fact_den[0] = 1;
    for(long long i=1; i<=N; i++) fact_den[i] = (fact_den[i-1] * fact_denpow[i]) % MOD;
}

// mCn
long long comb(const vector<long long> &fact_num, const vector<long long> &fact_den, long long m, long long n){
    return ((fact_num[m] * fact_den[n]) % MOD * fact_den[m-n]) % MOD;
}

long long solve(long long N, long long M){
    long long ret = 0;
    for(long long i=1; i<N; i++){
        ret += (i*(N-i)) % MOD;
        ret %= MOD;
    }
    ret = (ret * M*M) % MOD;
    return ret;
}

int main(){
    long long N, M, K;
    cin >> N >> M >> K;
    set_table(N*M+10, fact_num, fact_den);

    long long ans = (solve(N, M) + solve(M, N)) % MOD;
    ans = (ans * comb(fact_num, fact_den, N*M-2, K-2)) % MOD;
    cout << ans << endl;
    return 0;
}