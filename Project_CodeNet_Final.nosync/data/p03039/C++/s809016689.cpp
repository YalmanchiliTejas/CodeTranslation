#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
constexpr ll MOD = 1000000007LL;

vector<ll> fact(200010,0), factinv(200010,0);

ll exp(ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = ans * b % MOD;
        e >>= 1;
        b = b * b % MOD;
    }
    return ans;
}

void pp(void) {
    fact[0] = 1;
    for (ll i=1;i<=200000;i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    factinv[0] = 1;
    factinv[1] = 1;
    for (ll i=2;i<=200000;i++) {
        factinv[i] = exp(fact[i],MOD-2) % MOD;
    }
}

int main(void) {
    ll N, M, K;
    cin >> N >> M >> K;

    pp();
    ll ans1 = N * (N-1) % MOD;
    ans1 = ans1 * (N+1) % MOD;
    ans1 = (ans1 * M % MOD) * M % MOD;
    ll ans2 = M * (M-1) % MOD;
    ans2 = ans2 * (M+1) % MOD;
    ans2 = (ans2 * N % MOD) * N % MOD;
    ll ans = ans1 + ans2;
    ans %= MOD;
    ans = ans * exp(6,MOD-2) % MOD;
    ans = ans * fact[N*M-2] % MOD;
    ans = ans * factinv[K-2] % MOD;
    ans = ans * factinv[N*M-K] % MOD;
    cout << ans << endl;

    return 0;
}
