#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    REP(i, 0, N) cin >> A[i];
    sort(ALL(A));

    ll ans = 0;;
    if (N % 2 == 0) {
        ans = 2 * accumulate(A.begin() + N / 2, A.end(), 0LL) - 2 * accumulate(A.begin(), A.begin() + N / 2, 0LL) - A[N / 2] + A[N / 2 - 1];
    } else {
        ans = max(ans, 2 * accumulate(A.begin() + N / 2, A.end(), 0LL) - 2 * accumulate(A.begin(), A.begin() + N / 2, 0LL) - A[N / 2] - A[N / 2 + 1]);
        ans = max(ans, 2 * accumulate(A.begin() + (N + 1) / 2, A.end(), 0LL) - 2 * accumulate(A.begin(), A.begin() + (N + 1) / 2, 0LL) + A[N / 2] + A[N / 2 - 1]);
    }

    cout << ans << endl;
    
    return 0;
}