#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
#define PRYES(x) PR((x) ? "Yes" : "No")
const long long INF = numeric_limits<long long>::max();
int main() {
    ll N;

    cin >> N;
    vector<ll> values(N);
    REP(i, N) {
        cin >> values[i];
    }

    ll sum = values[N - 1];
    ll ans = 0;

    for (ll i = N - 2; i >= 0; --i) {
        ans += values[i] * sum % MOD;
        ans %= MOD;
        sum += values[i];
        sum %= MOD;
    }

    PR(ans);

    return 0;
}