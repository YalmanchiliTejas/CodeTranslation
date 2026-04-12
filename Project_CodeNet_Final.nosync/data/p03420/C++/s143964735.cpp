#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    // a = b * q + r (r >= K)
    // b > K
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for (int b = K + 1; b <= N; b++) {
        ans += N / b * (b - K) + max(0LL, N % b - K + 1);
    }
    if (K == 0) ans = N * N;
    cout << ans << "\n";
}