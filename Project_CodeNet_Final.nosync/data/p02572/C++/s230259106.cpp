#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(0);
    const int64_t MOD = 1e9 + 7;
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(auto &a : A)
        cin >> a;

    int64_t sum_a = accumulate(A.begin(), A.end(), 0LL);
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        sum_a -= A[i];
        ans = ((A[i] * (sum_a % MOD)) % MOD + ans) % MOD;
    }

    cout << ans << endl;

    return 0;
}