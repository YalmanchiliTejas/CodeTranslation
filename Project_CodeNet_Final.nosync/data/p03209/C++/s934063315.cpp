#include <bits/stdc++.h>
using namespace std;

long long p[51], b[51];

long long solve(long long N, long long X) {
    if (N == 0) {
        return X >= 1;
    }
    else if (X <= b[N-1] + 1) {
        return solve(N-1, X-1);
    }
    else {
        return p[N-1] + 1 + solve(N-1, X-2-b[N-1]);
    }
}

int main() {
    long long N, X;
    cin >> N >> X;
    p[0] = b[0] = 1LL;
    for (int i=1; i<=N; i++) {
        p[i] = p[i-1] * 2 + 1;
        b[i] = b[i-1] * 2 + 3;
    }
    cout << solve(N, X) << endl;
    return 0;
}
