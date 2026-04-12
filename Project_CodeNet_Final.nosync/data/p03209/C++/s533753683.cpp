#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(vector<ll> &A, vector<ll> &P, ll N, ll X) {
    if (N == 0) {
        if (X <= 0) return 0;
        else return 1;
    } else if (X <= 1 + A[N - 1]) {
        return f(A, P, N - 1, X - 1);
    }  else {
        return P[N - 1] + 1 + f(A, P, N - 1, X - 2 - A[N - 1]);
    }
}

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N + 1), P(N + 1);
    A[0] = 1, P[0] = 1;
    for (int i = 1; i <= N; i++) {
        A[i] = A[i - 1] * 2 + 3;
        P[i] = P[i - 1] * 2 + 1;
    }

    cout << f(A, P, N, X) << endl;
    return 0;
}