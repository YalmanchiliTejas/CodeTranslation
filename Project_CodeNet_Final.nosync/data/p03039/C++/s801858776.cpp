#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr ll MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

template <typename T>
T mypow(T a, T b)
{
    if (b == 0)
        return 1;
    T tmp = mypow(a, b / 2);
    if (b % 2)
        return (((tmp * tmp) % MOD) * a) % MOD;
    else
        return (tmp * tmp) % MOD;
}

vector<ll> fact(200020, 1), inv(200020, 1);

ll comb(int n, int k)
{
    if (k < 0 || n < k)
        return 0;
    ll ret = fact[n] * inv[k] % MOD;
    return ret * inv[n - k] % MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 2; i <= 200000; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = mypow(fact[i], MOD - 2);
    }
    ll ret = 0;
    for (int d = 1; d <= n - 1; d++)
    {
        ll sum = comb(n * m - 2, k - 2) * (n - d) % MOD;
        sum *= m * m % MOD;
        sum %= MOD;
        sum = sum * d % MOD;
        ret = (ret + sum) % MOD;
    }
    for (int d = 1; d <= m - 1; d++)
    {
        ll sum = comb(n * m - 2, k - 2) * (m - d) % MOD;
        sum *= n * n % MOD;
        sum %= MOD;
        sum = sum * d % MOD;
        ret = (ret + sum) % MOD;
    }
    cout << ret << endl;
}
