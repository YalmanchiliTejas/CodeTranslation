#include <bits/stdc++.h>
#define show(x) cerr << #x << " = " << x << endl
using namespace std;
using ll = long long;

ll power(const ll a, const ll n, const ll mod)
{
    if (n == 0) {
        return 1;
    } else if (n % 2 == 1) {
        return power(a, n - 1, mod) * a % mod;
    } else {
        const ll aa = power(a, n / 2, mod);
        return aa * aa % mod;
    }
}

class ModCombination
{
public:
    ModCombination(const int n, const ll mod) : size{n + 1}, mod{mod}, fact(n + 1, 1), inv(n + 1, 1), inv_fact(n + 1, 1)  // mod should be prime
    {
        for (ll i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
            inv[i] = ((mod - (mod / i)) * inv[mod % i]) % mod;
            inv_fact[i] = (inv_fact[i - 1] * inv[i]) % mod;
        }
    }
    ll combination(const int n, const int k) const
    {
        assert(n < size);
        assert(k <= n);
        return (((fact[n] * inv_fact[k]) % mod) * inv_fact[n - k]) % mod;
    }

private:
    const int size;
    const ll mod;
    vector<ll> fact;
    vector<ll> inv;
    vector<ll> inv_fact;
};
int main()
{
    int N;
    cin >> N;
    ll M;
    cin >> M;

    vector<ll> pp(N + 1);
    for (int i = 0; i <= N; i++) { pp[i] = power(2, power(2, i, M - 1), M); }
    ModCombination mod(N + 1, M);
    vector<vector<ll>> b(N + 2, vector<ll>(N + 2, 0));
    b[0][0] = 1;
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 1; j <= i; j++) { b[i][j] = (b[i - 1][j - 1] + j * b[i - 1][j] % M) % M; }
    }
    vector<ll> weight(N + 1, 0);
    for (int k = 1; k <= N; k++) {
        const ll p = power(2, N - k, M);
        const ll PP = pp[N - k] * mod.combination(N, k) % M;
        for (ll x = 1, q = 1; x <= k + 1; x++, (q *= p) %= M) { (weight[k] += b[k + 1][x] * q % M) %= M; }
        (weight[k] *= PP) %= M;
    }
    ll minus = 0;
    for (int i = 1; i <= N; i++) { (minus += (i % 2 == 0 ? weight[i] : M - weight[i])) %= M; }
    cout << (pp[N] + minus) % M << endl;

    return 0;
}
