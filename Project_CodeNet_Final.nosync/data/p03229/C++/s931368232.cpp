#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    sort(ALL(A));
    ll ans = 0;
    for (int i = 0; i < N/2; i++) ans -= 2 * A[i];
    for (int i = N/2; i < N; i++) ans += 2 * A[i];
    if (N % 2 == 0) {
        ans += A[N/2-1] - A[N/2];
    } else {
        ans = max(ans - A[N/2+1] - A[N/2], ans - 4 * A[N/2] + A[N/2] + A[N/2-1]);
    }
    cout << ans << endl;
}