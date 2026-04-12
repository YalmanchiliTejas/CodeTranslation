#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll calc_pow(ll x, ll pow) {
    if (pow == 0) return 1;
    ll a = calc_pow(x, pow / 2);
    a = a * a % MOD;
    if (pow % 2 == 1) a *= x;
    return a % MOD;
}

ll calc_div(ll b) {
    return calc_pow(b, MOD - 2) % MOD;
}

vector<ll> fact;

void init_fact(int n) {
    fact = vector<ll>(n);
    fact[0] = 1;
    for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % MOD;
}

ll calc_comb(ll n, ll r) {
    if (n < r)return 0;
    return fact[n] * calc_div(fact[r] * fact[n - r] % MOD) % MOD;
}

int main() {
    init_fact(100000);

    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    vector<ll> dp(n + 1);
    dp[n] = 1;
    for (int people = a; people <= b; people++) {
        vector<ll> nowdp(n + 1);

        ll divide = 1;
        for (int i = 1; i < c; i++) {
            divide *= calc_comb(people * i, people), divide %= MOD;
            divide *= calc_div(i), divide %= MOD;
        }

        for (int group = c; group <= d && people * group <= n; group++) {
            int count = people * group;

            divide *= calc_comb(count, people), divide %= MOD;
            divide *= calc_div(group), divide %= MOD;
            for (int prev = n; prev - count >= 0; prev--) {
                ll x = dp[prev] * calc_comb(prev, count) % MOD;
                nowdp[prev - count] += x * divide % MOD, nowdp[prev - count] %= MOD;
            }
        }

        for (int i = 0; i <= n; i++)dp[i] += nowdp[i], dp[i] %= MOD;
    }

    cout << dp[0] << endl;
    return 0;
}