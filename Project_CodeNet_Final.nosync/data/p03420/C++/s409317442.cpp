#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    long long ans = 0;
    for (int b=K+1; b<=N; ++b) {
        ans += ((N+1) / b) * (b - K);
        ans += max(0, (N+1) % b - K);
        if (K == 0) ans --;
    }

    cout << ans << endl;

    return 0;
}