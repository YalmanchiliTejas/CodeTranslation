#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for (ll b = K + 1; b <= N; b++) {
        for (ll k = 0; b * k + K <= N; k++) {
            ans += min(N, b * (k + 1) - 1) - max(1LL, (b * k + K)) + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
