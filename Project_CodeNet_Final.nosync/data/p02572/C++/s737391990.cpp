#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(_) cerr << #_ << ": " << (_) << '\n'
#define _GLIBCXX_DEBUG
#else
#define debug(_) (void(0))
#endif  // LOCAL

const long long MOD = 1000000007;

int main(){
    int N;
    vector<long long> As;
    long long sumA = 0, sumAsqrd = 0;

    cin >> N;
    As.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> As[i];
        sumA += As[i];
        sumAsqrd += As[i] * As[i] % MOD;
        sumA %= MOD;
        sumAsqrd %= MOD;
    }

    cout << (sumA * sumA + MOD * 10 - sumAsqrd) % MOD * 500000004 % MOD << '\n';

    return 0;
}