#include <bits/stdc++.h>

#define llint long long int
#define MOD 1000000007

using namespace std;

// a^n (mod p)
llint mod_pow(llint a, llint n, llint p)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        llint d = mod_pow(a, n / 2, p);

        return (d * d) % p;
    }
    else
    {
        return (a * mod_pow(a, n - 1, p)) % p;
    }
}
llint mod_inv(llint a, llint p)
{
    return mod_pow(a, p - 2, p);
}
int main()
{
    int N;

    cin >> N;

    llint sum1 = 0;
    llint sum2 = 0;

    for (int i = 0; i < N; i++)
    {
        llint A;

        cin >> A;

        sum1 = (sum1 + A) % MOD;
        sum2 = (sum2 + (A * A) % MOD) % MOD;
    }
    cout << ((((sum1 * sum1) % MOD - sum2 + MOD) % MOD) * mod_inv(2, MOD)) % MOD << endl;
}