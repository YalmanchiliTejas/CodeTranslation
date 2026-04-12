#include <bits/stdc++.h>
using namespace std;

typedef long long llt;

const int MaxN = 50 + 5;

int N; llt X;
llt P[MaxN], Size[MaxN];

llt solve(llt l, llt r, int n) {
    // printf("solve(%lld, %lld, %d)\n", l, r, n);
    if (n == 0) return 1;
    if (r <= n) return 0;
    llt m = (Size[n] >> 1) + 1ll;

    if (r < m) {
        return solve(1, r - 1, n - 1);
    } else if (r == m) {
        return solve(1, r - 2, n - 1) + 1ll;
    } else {
        return P[n - 1] + solve(1, r - m, n - 1) + 1ll;
    }
}

int main() {
    cin >> N >> X;
    P[0] = 1ll;
    for (int i = 1; i <= N; ++i) P[i] = P[i - 1] * 2ll + 1ll;
    Size[0] = 1ll;
    for (int i = 1; i <= N; ++i) Size[i] = Size[i - 1] * 2ll + 3ll;
    cout << solve(1ll, X, N) << endl;
    return 0;
}