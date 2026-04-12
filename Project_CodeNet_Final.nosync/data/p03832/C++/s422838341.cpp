#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e3 + 100, INF = 1e9 + 10, MOD = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, a, b, c, d, dp[SIZE][2];
vector<ll> fact;

void input() {
    cin >> n >> a >> b >> c >> d;
}

ll pw(ll a, ll b, ll md) { ll res = 1; while (b) { if (b & 1) { res = (a*res) % md; }a = (a*a) % md; b >>= 1; }return(res); }

ll pick(ll mn, ll am) {
    return (fact[mn] * pw(fact[am], MOD - 2, MOD)) % MOD;
}
void sol() {
    dp[0][0] = 1;

    fact.push_back(1);
    for (int i = 1; i <= n + 2; i++) fact.push_back((fact.back() * i) % MOD);

    ll ind = 0;
    for (int cur = a; cur <= b; cur++) {
        ind = !ind;
        for (int i = 0; i <= n; i++) dp[i][ind] = dp[i][!ind];

        for (int j = c; j <= d; j++) {
            for (int i = n; i >= 0; i--) {
                ll amount = cur * j;
                if (i - amount >= 0) {
                    dp[i][ind] += ((dp[i - amount][!ind] * (pw(pw(fact[cur], MOD - 2, MOD), j, MOD)) % MOD) % MOD * pw(fact[j], MOD - 2, MOD)) % MOD;
                    dp[i][ind] %= MOD;
                }
                else {
                    break;
                }
            }
        }
    }

    cout << (dp[n][ind] * fact[n]) % MOD;
}

int main()
{
    fastInp;

    ll t = 1;

    while (t--) {
        input();
        sol();
    }

    return 0;
}