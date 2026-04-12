#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<v> vv;
const ll MOD = 1e9 + 7;

template<typename T>
T pomod(T x, T y, T mod) {
    T res = 1;
    x = x % mod;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll inv(ll x) {
    return pomod(x, MOD - 2, MOD);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    v fact, invfact;
    fact = v(n + 1);
    invfact = v(n + 1);
    fact[0] = invfact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
        invfact[i] = inv(fact[i]);
    }

    vv ncr(n + 1, v(n + 1, 0));
    for (ll x = 1; x <= n; x++) {
        ncr[x][0] = 1;
        for (ll y = 1; y <= x; y++) {
            ncr[x][y] = ((ncr[x][y - 1] * (x - y + 1)) % MOD) * inv(y);
            ncr[x][y] %= MOD;
        }
    }

    vector<vv> combi(n + 1, vv(n + 1));
    for (ll sum = 1; sum <= n; sum++) {
        for (ll groupSize = 1; groupSize <= n; groupSize++) {
            ll curr = 1, left = sum;

            for (ll use = 1; use <= n; use++) {
                if (groupSize * use > sum)break;
                curr *= ncr[left][groupSize];
                curr %= MOD;
                left -= groupSize;

                ll ans = curr * invfact[use];
                ans %= MOD;
                combi[sum][groupSize].push_back(ans);
            }
        }
    }

    vv dp(n + 2, v(n + 2, 0));
    dp[0][b] = 1;
    for (ll i = c; i <= d; i++) {
        if (i * b > n)break;
        dp[i * b][b] = combi[i * b][b][i - 1];
    }

    for (ll groupSize = b - 1; groupSize >= a; groupSize--) {
        for (ll usage = c; usage <= d; usage++) {
            ll sum = groupSize * usage;

            for (ll s = sum; s <= n; s++) {
                ll add = combi[s][groupSize][usage - 1] * dp[s - sum][groupSize + 1];
                add %= MOD;
                dp[s][groupSize] += add;
                dp[s][groupSize] %= MOD;
            }
        }
        for (ll s = 0; s <= n; s++) {
            dp[s][groupSize] += dp[s][groupSize + 1];
            dp[s][groupSize] %= MOD;
        }
    }

    cout << dp[n][a] << endl;
    return 0;
}