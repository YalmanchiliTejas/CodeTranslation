#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;

long long f(long long N, long long X, vector<long long> &len, vector<long long> &p) {
    if (N == 0) {
        return 1;
    }

    if (X == 1) {
        return 0;
    } else if (X <= 1 + len[N - 1]) {
        return f(N - 1, X - 1, len, p);
    } else if (X == 2 + len[N - 1]) {
        return p[N - 1] + 1;
    } else if (X <= 2 + 2 * len[N - 1]) {
        return p[N - 1] + 1 + f(N - 1, X - 2 - len[N - 1], len, p);
    } else {
        return 2 * p[N - 1] + 1;
    }
}

int main() {
    long long N, X;
    cin >> N >> X;

    vector<long long> len(N + 1);
    vector<long long> p(N + 1);

    len[0] = p[0] = 1;
    for (int i = 1; i < N + 1; i++) {
        len[i] = len[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }

    cout << f(N, X, len, p) << endl;
    return 0;
}