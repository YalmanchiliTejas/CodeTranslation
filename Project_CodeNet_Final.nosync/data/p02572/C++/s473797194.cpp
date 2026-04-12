#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    int N;  cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum = (sum + A[i]) % MOD;
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        sum -= A[i];
        while (sum < 0) sum += MOD;
        sum %= MOD;
        ans = (ans + A[i] * sum) % MOD;
    }
    cout << ans << endl;
}
