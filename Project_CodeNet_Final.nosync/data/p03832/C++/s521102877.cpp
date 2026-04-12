#include <bits/stdc++.h>

#define VARNAME(x) #x
#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "sz:" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}

template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}


constexpr ll MOD = (ll)1e9 + 7LL;

template <typename T>
constexpr T INF = numeric_limits<T>::max() / 100;

class Modulo
{
public:
    Modulo(const int n, const ll mod = 1000000007LL) : m_size{n + 1}, m_mod{mod}  // mod should be prime
    {
        assert(n > 0);
        m_fact.resize(n + 1);
        m_inv.resize(n + 1);
        m_inv_fact.resize(n + 1);
        m_fact[0] = 1;
        m_inv[0] = 1;
        m_inv_fact[0] = 1;
        m_fact[1] = 1;
        m_inv[1] = 1;
        m_inv_fact[1] = 1;
        for (int i = 2; i <= n; i++) {
            m_fact[i] = (m_fact[i - 1] * static_cast<ll>(i)) % mod;
            m_inv[i] = ((mod - (mod / static_cast<ll>(i))) * m_inv[static_cast<unsigned int>(mod) % i]) % mod;
            m_inv_fact[i] = (m_inv_fact[i - 1] * m_inv[i]) % mod;
        }
    }

    ll factorial(const int n) const
    {
        assert(n < m_size);
        return m_fact[n];
    }

    ll inverse(const int n) const
    {
        assert(n < m_size);
        return m_inv[n];
    }

    ll inverseFactorial(const int n) const
    {
        assert(n < m_size);
        return m_inv_fact[n];
    }

    ll permutation(const int n, const int k) const
    {
        assert(n < m_size);
        assert(k <= n);
        return (m_fact[n] * m_inv_fact[n - k]) % m_mod;
    }

    ll combination(const int n, const int k) const
    {
        assert(n < m_size);
        assert(k <= n);
        return (((m_fact[n] * m_inv_fact[k]) % m_mod) * m_inv_fact[n - k]) % m_mod;
    }

private:
    const int m_size;
    const ll m_mod;
    vector<ll> m_fact;
    vector<ll> m_inv;
    vector<ll> m_inv_fact;
};

int A, B, C, D;

ll dp(const int ind, const int rest, vector<vector<int>>& memo, const Modulo& mod)
{
    if (ind == B - A + 1) {
        return (rest == 0 ? 1 : 0);
    }
    if (memo[ind][rest] != -1) {
        return memo[ind][rest];
    }
    const int num = A + ind;
    ll sum = 0;
    sum += dp(ind + 1, rest, memo, mod);
    if (rest < num * C) {
        memo[ind][rest] = sum;
        return sum;
    }
    int n = rest;
    ll prod = 1;
    ll inv = 1;
    for (int i = 0; i < C; i++) {
        prod *= mod.combination(n, num);
        inv *= mod.inverse(i + 1);
        prod %= MOD;
        inv %= MOD;
        n -= num;
    }
    for (int i = C; i <= D; i++) {
        sum += (dp(ind + 1, n, memo, mod) * prod % MOD) * inv;
        sum %= MOD;
        if (n < num) {
            break;
        }
        prod *= mod.combination(n, num);
        inv *= mod.inverse(i + 1);
        prod %= MOD;
        inv %= MOD;
        n -= num;
    }
    memo[ind][rest] = sum;
    return sum;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    cin >> A >> B;
    cin >> C >> D;

    vector<vector<int>> memo(B - A + 1, vector<int>(N + 1, -1));
    const Modulo mod(N);
    cout << dp(0, N, memo, mod) << endl;

    return 0;
}
