#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    vector<ll> S(N);
    for (int i = N - 1; i >= 0; --i) {
        if (i == N - 1) S[i] = 0;
        else S[i] = (A[i + 1] + S[i + 1]) % ((int)1e9 + 7);
    }
    ll ans = 0;
    rep(i, N) {
        ans = (ans + A[i] * S[i]) % ((int)1e9 + 7);
    }
    cout << ans << endl;
    return 0;
}
