#include "bits/stdc++.h"

using namespace std;

const long long MOD = 1000000007;

void Main() {
    long long N;
    cin >> N;
    vector<long long> A(N, 0LL);
    long long total = 0LL;
    for (long long i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
        total %= MOD;
    }

    vector<long long> accum(N, 0LL);
    accum[0] = A[0];
    for (long long i = 1; i < N; ++i) {
        accum[i] = accum[i - 1] + A[i];
    }

    long long ans = 0LL;
    for (long long i = 0; i < N - 1; ++i) {
        long long temp = (A[i] * ((total - accum[i]) % MOD)) % MOD;
        ans += temp;
        ans %= MOD;
    }
    if (ans < 0) {
        ans += MOD;
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
