#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<long long> a_sum(N, 0);
    for (int i = N-2; i >= 0; i--)
    {
        a_sum[i] = (a_sum[i+1] + A[i+1]) % MOD;
    }
    long long ans = 0;
    for (int i = 0; i < N-1; i++)
    {
        ans = (ans + (A[i] * a_sum[i]) % MOD) % MOD;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}