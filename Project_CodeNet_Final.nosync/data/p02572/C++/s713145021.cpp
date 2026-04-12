#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<long long> B(N + 1, 0);  // 累積和テーブル

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        B[i + 1] = B[i] + A[i];
    }

    long ans = 0;
    int mod = 1000000007;

    for(int i = 0; i < N; i++) {
        long long sum = (B[N] - B[i + 1]) % mod;
        ans += A[i] * sum;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}