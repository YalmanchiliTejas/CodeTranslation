#include<iostream>
using namespace std;
typedef long long ll;;

const ll MOD = 1e9 + 7;
const ll MAX_NM = 2 * 1e5 + 2;

ll factorial[MAX_NM];

ll calc_pow(ll x, ll y) {
    ll z = 1;
    while (y > 0) {
        if (y & 1) {
            z = (z * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return z;
}

ll calc_comb(ll x, ll y) {
    ll div_num = (factorial[x - y] * factorial[y]) % MOD;
    return (factorial[x] * calc_pow(div_num, MOD - 2)) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    factorial[0] = 1;
    for (ll i = 1; i <= N * M; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    ll ans = 0;
    for (ll i = 1; i <= M; i++) {
        ll dist_sum = ((M - i) * (2 + (M - i - 1)) / 2) % MOD;
        ans = (ans + (((((N * N) % MOD) * calc_comb(N * M - 2, K - 2)) % MOD) * dist_sum) % MOD) % MOD;
    }
    for (ll i = 1; i <= N; i++) {
        ll dist_sum = ((N - i) * (2 + (N - i - 1)) / 2) % MOD;
        ans = (ans + (((((M * M) % MOD) * calc_comb(N * M - 2, K - 2)) % MOD) * dist_sum) % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}