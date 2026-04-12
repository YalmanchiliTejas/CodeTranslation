#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    long long ans = 0;
    for (int b = 1; b <= N; b++) {
        ans += (N / b) * max(b - K, 0);
        ans += K > 0 ? max(N % b - K + 1, 0) : N % b;
    }
    cout << ans << endl;
}