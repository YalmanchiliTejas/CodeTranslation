#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()
#define MOD 1000000007

ll fact[200000], fact_i[200000];

ll power(int x, int y) {
    if (y == 1) return x;
    ll p = power(x, y >> 1);
    if (y & 1) return p * p % MOD * x % MOD;
    else return p * p % MOD;
}

ll inv(ll n) {
    return power(n, MOD - 2);
}

void init(int n) {
    fact[0] = 1;
    REP(i, n) fact[i + 1] = fact[i] * (i + 1) % MOD;
    fact_i[n] = inv(fact[n]);
    REP(i, n) fact_i[n - i - 1] = fact_i[n - i] * (n - i) % MOD;
}

ll nCr(ll n, ll r) {
    return fact[n] * fact_i[r] % MOD * fact_i[n - r] % MOD;
}

int main() {
    init(200000);
    ll N, M, K;
    cin >> N >> M >> K;

    ll ans = 0;
    FOR(i, 1, N) {
        ans += i * (N - i) % MOD * M * M % MOD;
        ans %= MOD;
    }
    FOR(i, 1, M) {
        ans += i * (M - i) % MOD * N * N % MOD;
        ans %= MOD;
    }
    ans = ans * nCr(N*M-2, K-2) % MOD;


    // FOR(i, 1, N) ans = (ans + i * (N - i) % MOD * M * M % MOD) % MOD;
    // FOR(i, 1, M) ans = (ans + i * (M - i) % MOD * N * N % MOD) % MOD;
    // ans = ans * nCr(N * M - 2, K - 2) % MOD;
    cout << ans << endl;
    return 0;
}
