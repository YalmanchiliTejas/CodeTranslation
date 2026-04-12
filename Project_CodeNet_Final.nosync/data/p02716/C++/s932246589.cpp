#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> f[2], b[2];
    f[0].push_back(A[0]), f[1].push_back(A[1]);
    b[0].push_back(A[N - 1]), b[1].push_back(A[N - 2]);
    for (int i = 2; i + 1 < N; i += 2)
        f[0].push_back(f[0].back() + A[i]),
            f[1].push_back(max(f[1].back(), f[0][f[0].size() - 2]) + A[i + 1]);
    for (int i = N - 3; i - 1 >= 0; i -= 2)
        b[0].push_back(b[0].back() + A[i]),
            b[1].push_back(max(b[1].back(), b[0][b[0].size() - 2]) + A[i - 1]);

    if (N % 2 == 0) {
        cout << max(f[0].back(), f[1].back()) << endl;
    } else if (N == 3) {
        cout << max({A[0], A[1], A[2]}) << endl;
    } else {
        ll ans =
            max(max({A[0], A[1], A[2]}) + b[0][(N - 5) / 2], max({A[0], A[1]}) + b[1][(N - 5) / 2]);
        for (int i = 0; (i + 1) * 2 + 3 < N; i++) {
            ll x;
            int j = (N - 7) / 2 - i;
            int k = (i + 1) * 2;
            x = max({f[0][i] + b[0][j] + max({A[k], A[k + 1], A[k + 2]}),
                     f[1][i] + b[0][j] + max(A[k + 1], A[k + 2]),
                     f[0][i] + b[1][j] + max(A[k], A[k + 1]), f[1][i] + b[1][j] + A[k + 1]});
            ans = max(ans, x);
        }
        ll x = max(max({A[N - 1], A[N - 2], A[N - 3]}) + f[0][f[0].size() - 2],
                   max(A[N - 1], A[N - 2]) + f[1][f[1].size() - 2]);
        ans = max(ans, x);
        cout << ans << endl;
    }

    return 0;
}