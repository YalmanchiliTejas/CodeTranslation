#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

void solve() {
    ll N, K, ans = 0;
    cin >> N >> K;
    if (K == 0) ans = N * N;
    else for (ll b = K + 1; b <= N; b++) {
        ans += (b - K) * (N / b);
        if (N % b - K + 1 > 0) ans += N % b - K + 1;
    }
    cout << ans << endl;
    return;
}

int main() {
    solve();
}