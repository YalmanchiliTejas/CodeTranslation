#include <iostream>
#include <array>
using namespace std;

using ll = long long;

// ModCombination
namespace MC {
    const int MAX_N = 4010;   // 10^6
    const ll MOD = 1000000007;  // 10^9+7

    array<ll, 2 * MAX_N + 1> fact;
    array<ll, 2 * MAX_N + 1> inv_fact;  // n!の逆元

    ll pow(ll a, ll b) {
        if (b == 0) return 1;
        else if (b % 2 == 0) {
            ll d = pow(a, b / 2);
            return (d * d) % MOD;
        } else {
            return (a * pow(a, b - 1)) % MOD;
        }
    }

    ll factorial(ll n) {
        return fact[n];
    }

    ll inverse(ll n) {
        return pow(n, MOD - 2);
    }

    ll inverse_factorial(ll n) {
        return inv_fact[n];
    }

    ll nPk(ll n, ll k) {
        if (n < 0 || n < k) return 0;
        else return (factorial(n) * inverse_factorial(n - k)) % MOD;
    }

    ll nCk(ll n, ll k) {
        if (n < 0 || n < k) return 0;
        else return (nPk(n, k) * inverse_factorial(k)) % MOD;
    }

    ll nHk(ll n, ll k) {
        if (n < 0 || k < 0) return 0;
        else if (k == 0) return 1;
        else return nCk(n + k - 1, k);
    }

    // 要素がn個あるとき
    void initialize(int n) {
        if (2 * n > 2 * MAX_N) {
            cerr << "現在のfactのサイズでは足りない可能性があります" << endl;
            exit(1);
        }

        // 階乗%MODを計算
        fact[0] = 1;
        for (ll i = 1; i <= 2 * MAX_N; i++) {
            fact[i] = (i * fact[i - 1]) % MOD;
        }
        // mod逆元の階乗を計算
        inv_fact[2 * MAX_N] = inverse(factorial(2 * MAX_N));
        for (ll i = 2 * MAX_N - 1; i >= 0; i--) {
            inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;
        }
    }
};

ll dp[2000][2000];
ll nPk[2000][2000];

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    const ll MOD = MC::MOD;

    for (int i = N; i >= 1; i--) {
        ll val = 1;
        for (int j = 1; j <= i; j++) {
            (val *= (i - j + 1)) %= MOD;
            nPk[i][j] = val;
        }
    }

    MC::initialize(N);
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            if (dp[i][j] == 0) continue;
            (dp[i + 1][j] += dp[i][j]) %= MOD;

            if (i + 1 < A or i + 1 > B) continue;

            // i+1人のグループをいくつ作るか
            for (int k = C; k <= min(D, (N - j) / (i + 1)); k++) {
                // (i+1)!でグループの数だけ割る
                ll x = (((nPk[N - j][k * (i + 1)] * MC::pow(MC::inverse_factorial(i + 1), k)) % MOD) * MC::inverse_factorial(k)) % MOD;
                (dp[i + 1][j + (i + 1) * k] += x * dp[i][j]) %= MOD;
            }
        }
    }

    cout << dp[N][N] << endl;

    /*
    for (int i = 0; i <= N; i++) {
        cerr << "[" << i << "] ";
        for (int j = 0; j <= N; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    */

    return 0;
}