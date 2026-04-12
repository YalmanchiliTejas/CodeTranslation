#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    ll N, K;
    cin >> N >> K;
    if(K == 0) {
        cout << N * N << "\n";
        return 0;
    }
    ll ans = 0;
    for(int i = K + 1; i <= N; i++) {
        ans += (N / i) * (i - K);
        ans += max(0LL, N % i - K + 1);
    }
    cout << ans << "\n";
    return 0;
}
