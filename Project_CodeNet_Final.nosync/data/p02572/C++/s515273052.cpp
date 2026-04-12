#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), S(N + 1, 0);
    ll MOD = 1e9 + 7;
    rep(i, N) {
        cin >> A[i];
        S[i + 1] = (S[i] + A[i]) % MOD;
    }
    ll ans = 0;
    rep(i, N) {
        ans = (ans + S[i] * A[i]) % MOD;
    }
    cout << ans << "\n";
}