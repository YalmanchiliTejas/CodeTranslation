#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    int x = N / 2;
    ll ans = 0, ans2 = 0;
    if (N % 2) {
        B[0] = A[N / 2];
        C[N - 1] = A[N / 2];
        rep(i, N / 2) {
            B[i * 2 + 1] = A[N / 2 + i + 1];
            B[i * 2 + 2] = A[i];
            C[i * 2] = A[N / 2 + i + 1];
            C[i * 2 + 1] = A[i];
        }
        rep(i, N - 1) {
            ans += abs(B[i] - B[i + 1]);
            ans2 += abs(C[i] - C[i + 1]);
        }
        if (ans2 > ans) ans = ans2;
    } else {
        rep(i, N / 2) {
            B[i * 2] = A[N / 2 + i];
            B[i * 2 + 1] = A[i];
        }
        rep(i, N - 1) ans += abs(B[i] - B[i + 1]);
    }
    cout << ans << endl;
}