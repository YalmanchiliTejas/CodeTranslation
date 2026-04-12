#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define MOD 1000000007

const int MAX = 200005;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    ll x = (M * N * (M + N) * (M * N - 1)) / 6;
    x %= MOD;
    if (K == 2) {
        cout << x << endl;
        return 0;
    }
    else {
        COMinit();
        ll y = COM(M * N - 2, K - 2);
        cout << (x * y) % MOD << endl;
        return 0;
    }

}
