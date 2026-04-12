// 8/29 リアルタイム参加
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

ll mod = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> R(N);  // R(0) = 0番目から右の総和、R(N-1) = N-1番目から右の総和
    R[N-1] = 0;
    for (int i = N-1; i > 0; i--) {
        R[i-1] = R[i] + A[i];
        R[i-1] %= mod;
    }

    ll ans = 0;

    for (int i = 0; i < N-1; i++) {
        ans += A[i] * R[i];
        ans %= mod;
    }

    cout << ans << endl;
}