#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
pair<ll, ll> extgcd(const ll a, const ll b)
{
    if (b == 0) { return pair<ll, ll>{1, 0}; }
    const auto p = extgcd(b, a % b);
    return {p.second, p.first - p.second * (a / b)};
}
ll inverse(const ll a) { return (MOD + extgcd(a, MOD).first % MOD) % MOD; }
int main()
{
    while (true) {
        ll N, D, X;
        cin >> N >> D >> X;
        if (N == 0 and D == 0 and X == 0) { break; }
        vector<ll> dp1(N + 1, 1), dp2(N + 1, 0);
        auto get = [&](const ll i) { return (dp1[i - 1] + MOD - (i < X ? 0 : dp1[i - X])) % MOD; };
        for (ll i = 1; i <= N; i++) {
            for (ll j = N; j >= 1; j--) { dp1[j] = get(j); }
            dp2[i] = dp1[N], dp1[0] = 0;
            for (int j = 1; j <= N; j++) { (dp1[j] += dp1[j - 1]) %= MOD; }
        }
        auto comb = [&](const ll k) {
            if ((D % MOD) < k or D < k) { return 0LL; }
            ll ans = 1;
            for (ll j = D; j > D - k; j--) { (ans *= (j % MOD)) %= MOD; }
            for (ll j = 1; j <= k; j++) { (ans *= inverse(j)) %= MOD; }
            return ans;
        };
        ll ans = 0;
        for (ll i = 0; i <= N; i++) { (ans += (dp2[i] * comb(i) % MOD)) %= MOD; }
        cout << ans << endl;
    }
    return 0;
}

