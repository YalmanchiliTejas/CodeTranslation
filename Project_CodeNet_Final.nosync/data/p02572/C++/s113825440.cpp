#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MOD = 1000000007;

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

void solve(long long N, std::vector<long long> A)
{

    ll sum = 0;
    for (auto &&e : A)
    {
        sum += e;
        sum %= MOD;
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        ans += (A[i] * ((sum - A[i] + MOD) % MOD)) % MOD;
        ans %= MOD;
    }

    cout << ans * modinv(2, MOD) % MOD << endl;
}

signed main()
{
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
