// Problem E - Cell Distance
#include<bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;

long long int power(long long int x, long long int n)
{
    long long int res = 1;
    while(n > 0)
    {
        if(n&1)
        {
            res = (res * x)%mod;
        }
        x = (x * x)%mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    long long int n, m, k;
    cin >> n >> m >> k;

    vector<long long int> fac(n*m-1, 1);
    vector<long long int> ifac(n*m-1, 1);
    
    for(int i=2; i<n*m-1; i++)
    {
        fac[i] = (i * fac[i-1])%mod;
    }
    for(int i=1; i<n*m-1; i++)
    {
        ifac[i] = power(fac[i], mod-2);
    }

    long long int ans = 0;
    for(int i=1; i<m; i++)
    {
        long long int a = ((long long int)n * n * (m - i))%mod;
        ans += (a * i)%mod;
        ans %= mod;
    }
    for(int i=1; i<n; i++)
    {
        long long int a = ((long long int)m * m * (n - i))%mod;
        ans += (a * i)%mod;
        ans %= mod;
    }

    ans *= (fac[n*m - 2] * ifac[k - 2])%mod;
    ans %= mod;
    ans *= ifac[n*m - k];
    ans %= mod;

    cout << ans << endl;
    return 0;
}