#include <bits/stdc++.h>
using namespace std;
#define MOD ((long long)(1e9 + 7))

int main(void) {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> sum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        sum[i + 1] = sum[i] + A[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (A[i] * ((sum[N] - sum[i + 1]) % MOD)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}