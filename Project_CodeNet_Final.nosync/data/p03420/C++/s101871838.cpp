#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

template <typename T> constexpr T inf;
template <> constexpr int inf<int> = 1e9;
template <> constexpr ll inf<ll> = 1e18;
template <> constexpr double inf<double> = 1e18;

int main() {
    int N, K; cin >> N >> K;
    if(K == 0) {
        cout << 1LL * N * N << endl;
        return 0;
    }
    ll ans = 0;
    for(int b = K + 1; b <= N; ++b) {
        ans += N - K + 1 - (N - b) / b * K - min((N - b) % b + 1, K);
        //cout << ans << endl;
    }
    cout << ans << endl;
}