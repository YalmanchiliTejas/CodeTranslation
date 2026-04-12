#include <bits/stdc++.h>

using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

// 階乗、階乗逆元テーブル
int fact[1100000], fact_inv[1100000], inv[1100000];

int mod_fact(int n, int m) {
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < n; i++) {
        fact[i] = fact[i - 1] * i % m;
        inv[i] = m - inv[m % i] * (m / i) % m;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % m;
    }
}

int N, M, K;
int mod = 1e9 + 7;

signed main() {
    cin >> N >> M >> K;
    mod_fact(220000, mod);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int a = ((i * (i + 1) / 2 + (N - i - 1) * (N - i) / 2) * M +
                     (j * (j + 1) / 2 + (M - j - 1) * (M - j) / 2) * N) % mod;
            (a *= fact[N * M - 2] * fact_inv[K - 2] % mod * fact_inv[N * M - K] % mod) %= mod;
            (ans += a) %= mod;
        }
    }
    (ans *= inv[2]) %= mod;
    cout << ans << endl;

}