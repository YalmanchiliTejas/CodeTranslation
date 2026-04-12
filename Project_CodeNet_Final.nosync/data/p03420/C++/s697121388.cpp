#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for ( ll b = 1; b <= N; b++ ) {
        ans += (N/b) * max(b-K, 0LL);
        ans += K > 0 ? max(N%b-K+1, 0LL) : N%b;
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}