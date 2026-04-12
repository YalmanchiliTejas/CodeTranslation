#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

int main() {
    int N;  cin >> N;
    vector<ll> A(N);
    ll sum = 0, sum_diag = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum = (sum + A[i]) % MOD;
        sum_diag = (sum_diag + A[i] * A[i] % MOD) % MOD;
    }
    cout << (sum * sum % MOD - sum_diag + MOD) % MOD * 500000004 % MOD << endl;
}
