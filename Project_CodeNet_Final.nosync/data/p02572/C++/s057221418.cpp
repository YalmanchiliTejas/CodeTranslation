#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli mod = 1000000007;

unsigned long long power(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    lli n;
    cin>>n;
    lli x;
    lli sum = 0;
    lli sos = 0;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        sum = (sum + x)%mod;
        sos = (sos + (x*x))%mod;
    }

    lli y = (sum * sum)%mod;
    lli ans = (((y - sos + mod)%mod) * modInverse(2, mod))%mod;
    cout<<ans<<"\n";
}