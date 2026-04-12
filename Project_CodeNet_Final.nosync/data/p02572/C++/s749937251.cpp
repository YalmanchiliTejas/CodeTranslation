#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int64_t& a : A) {
        cin >> a;
    }

    int64_t ans = 0;
    constexpr int64_t MOD = 1e9 + 7;

    int64_t sum = A[0];
    for (int64_t i = 1; i < N; i++) {
        (ans += A[i] * sum) %= MOD;
        (sum += A[i]) %= MOD;
    }

    cout << ans << endl;
}