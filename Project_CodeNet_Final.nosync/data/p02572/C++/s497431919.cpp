#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define FOR(i, N) for (long i = 0; i < (N); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long> A(N);
    vector<long> Sum(N, 0);
    FOR(n, N) {
        cin >> A[n];
    }

    for (int n = N - 2; n >= 0; n--) {
        Sum[n] = (Sum[n + 1] + A[n + 1]) % MOD;
    }

    long ans = 0;
    FOR(n, N - 1) {
        ans = (ans + (A[n] * Sum[n]) % MOD) % MOD;
    }

    cout << ans << endl;
    return 0;
}
