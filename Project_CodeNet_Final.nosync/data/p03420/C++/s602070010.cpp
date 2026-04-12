#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
ll N, K;

signed main()
{
    ll ans = 0ll;
    cin >> N >> K;
    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }
    // N = p*b + r
    for (ll b = 1; b <= N; ++b) {
        ll r = N % b;
        ll p = N / b;
        ans += p * max(0ll, b - K); // b未満の数
        ans += max(0ll, r - (K - 1)); // b以上のあまり
    }
    cout << ans << endl;
    return 0;
}