#include <iostream>
using namespace std;

//===
// nCr mod p
// p is prime
// 1 <= k <= n <= 1e7

void init_comb(long long modulus);
void init_comb(void);
long long combination(long long n, long long k);
long long pow_mod(long long n, long long m);

long long _modulus = (long long)1e9 + 7;
long long fact[10000007];
long long fact_inv[10000007];

void init_comb(long long modulus) {_modulus = modulus; }
void init_comb(void)
{
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        fact[i] = fact[i - 1] * i % _modulus;
        fact_inv[i] = pow_mod(fact[i], _modulus - 2);
    }
}

long long combination(long long n, long long k)
{
    static long long f;

    if (f != _modulus) f = _modulus, init_comb();

    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return fact[n] * (fact_inv[k] * fact_inv[n - k] % _modulus) % _modulus;
}

long long pow_mod(long long n, long long m)
{
    //n ** m;
    long long ret = 1;

    while (m) {
        if (m & 1) {
            ret = ret * n % _modulus;
        }

        n = n * n % _modulus;
        m = m >> 1;
    }

    return ret;
}
//===

#define sum(X) ((X) * ((X) + 1) / 2 % mod)

typedef long long ll;

const ll mod = (ll)(1e9) + 7;

ll n, m;
ll k;
ll ans;

int main()
{
    cin >> n >> m >> k;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            ll d = sum(i - 1) * m % mod + sum(n - i) * m % mod +
                sum(j - 1) * n % mod + sum(m - j) * n % mod;
            d %= mod;

            ans += d * combination(n * m - 2, k - 2) % mod;
            ans %= mod;
        }
    }

    ans = ans * pow_mod(2, mod - 2) % mod;
    cout << ans << endl;

    return 0;
}
