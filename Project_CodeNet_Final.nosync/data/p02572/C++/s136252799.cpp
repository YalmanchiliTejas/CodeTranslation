#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; (i) < ((int)(n)); ++(i))
const ll INF = 10e10;
const ll MOD = 1000000007;

int main() {
    ll ans = 0;
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i];
    B[N - 1] = 0;
    rep(i, N - 1) {
        B[N - 2 - i] = (B[N - 1 - i] + A[N - 1 - i]) % MOD;
        // cout << B[N - 2 - i] << endl;
    }
    rep(i, N) {
        // cout << A[i] << " " << B[i] << endl;
        ans = (ans + (A[i] * B[i]) % MOD) % MOD;
    }
    cout << ans << endl;
}