#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
    ll N, X, M, A;
    cin >> N >> X >> M;
    vector<ll> R(M, -1), S(M + M, 0);
    A = X;
    R[A] = 0;
    S[1] = A;
    int B, C;
    rep(i, M + M) {
        A = (A * A) % M;
        //cout << "i=" << i << " A=" << A << "\n";
        S[i + 2] = S[i + 1] + A;
        if (R[A] != -1) {
            B = R[A];
            C = i + 1;
            break;
        }
        R[A] = i + 1;
    }
    /*
    cout << B << " " << C << "\n";
    rep(i, C - B + 1) {
        cout << "S[" << i + B << "]=" << S[i + B] << "\n";
    }
    */
    if (N <= C) {
        cout << S[N] << "\n";
        return 0;
    }
    ll q = (N - B) / (C - B);
    ll r = (N - B) % (C - B);
    ll ans = S[B] + q * (S[C] - S[B]) + S[B + r] - S[B];
    cout << ans << "\n";
}