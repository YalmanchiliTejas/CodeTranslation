#include <bits/stdc++.h>
using namespace std;
long long a[51];
long long b[51];
long long solve(long long N, long long X) {
    X = min(X, a[N]);
    if (N == 0 && X == 1) return 1;
    if (X <= 1) return 0;
    if (X < 2+a[N-1]) {
        return solve(N-1, X-1);
    }
    else {
        return b[N-1] + 1 + solve(N-1, X-(2+a[N-1]));
    }
}
int main () {
    long long N, X;
    cin >> N >> X;
    a[0] = 1;
    b[0] = 1;
    for (int i = 1; i <= N; i++) {
        a[i] = a[i-1]*2+3;
        b[i] = b[i-1]*2+1;
    }
    cout << solve(N, X) << endl;
}