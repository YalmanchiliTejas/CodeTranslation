#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int MOD = 998244353;
const int N = 1e7 + 12;

long long ans;
long long deg2[N], fact[N], ufact[N], r[N];

long long cnk(long long n, long long k)
{
    return fact[n] * ufact[k] % MOD * ufact[n - k] % MOD;
}

signed main()
{
    int n;
    cin >> n;
    deg2[0] = 1, fact[0] = 1, ufact[0] = 1, r[1] = 1;
    for (int i = 2; i < N; i++) r[i] = MOD - (MOD / i) * r[MOD % i] % MOD;
    for (int i = 1; i < N; i++) deg2[i] = deg2[i - 1] * 2 % MOD, fact[i] = fact[i - 1] * i % MOD, ufact[i] = ufact[i - 1] * r[i] % MOD;
    ans = 1;
    for (int i = 0; i < n; i++) ans = ans * 3 % MOD;
    for (int c = n / 2 + 1; c <= n; c++)
    {
        ans = (ans - cnk(n, c) * deg2[n - c + 1] + MOD * MOD) % MOD;
    }
    cout << ans;
}
