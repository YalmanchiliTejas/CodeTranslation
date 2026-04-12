#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    long long mod = 1E9 + 7;
    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + A[i]) % mod;
    }
    long long ans = 0;
    for (int i = 1; i < N; ++i) {
        ans = (ans + (A[i] * prefix_sum[i]) % mod) % mod;
    }
    cout << ans << '\n';
    return 0;
}