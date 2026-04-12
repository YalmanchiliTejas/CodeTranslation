#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

vector<ll> L;

ll getP(int N, ll X) {
    if (N == 0) {
        if (X > 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if (X <= 0) {
        return 0;
    } else if (X >= L[N]) {
        return 1 + 2 * getP(N - 1, L[N - 1]);
    } else if (X >= L[N - 1] + 2) {
        return getP(N - 1, L[N - 1]) + 1 + getP(N - 1, X - 2 - L[N - 1]);
    } else if (X >= 1) {
        return getP(N - 1, X - 1);
    }
}

int main() {
    int N;
    ll X;
    cin >> N >> X;

    L.resize(N + 1);
    L[0] = 1;
    for (int i = 1; i <= N; i++) {
        L[i] = 2 * L[i - 1] + 3;
    }
    cout << getP(N, X) << endl;
}
