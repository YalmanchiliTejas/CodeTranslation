#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end(), greater<ll>());

    if (N % 2 == 0) {
        ll ans = 0;
        rep(i, N / 2 - 1) ans += A[i] * 2;
        ans += A[N / 2 - 1];
        ans -= A[N / 2];
        for (int i = N / 2 + 1; i < N; i++) ans -= A[i] * 2;
        cout << ans << endl;
    } else {
        ll ans1 = 0;
        rep(i, N / 2 - 1) ans1 += A[i] * 2;
        ans1 += A[N / 2 - 1] + A[N / 2];
        for (int i = N / 2 + 1; i < N; i++) ans1 -= A[i] * 2;

        ll ans2 = 0;
        rep(i, N / 2) ans2 += A[i] * 2;
        ans2 -= A[N / 2] + A[N / 2 + 1];
        for (int i = N / 2 + 2; i < N; i++) ans2 -= A[i] * 2;

        cout << max(ans1, ans2) << endl;
    }
}