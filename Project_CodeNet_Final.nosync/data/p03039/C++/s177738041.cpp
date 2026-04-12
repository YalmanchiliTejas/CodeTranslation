#include <bits/stdc++.h>

using namespace std;

long long MOD=1000000007;

long long Pow(long long a, long long k)
{
    long long S=a, R=1, t=1;
    while (k > 0)
    {
        if (k % (2*t) != 0)
        {
            k -= t;
            R *= S;
            R %= MOD;
        }
        S *= S;
        S %= MOD;
        t *= 2;
    }
    return R;
}

int main()
{
    long long n, m, k, S=0, s, Sd, Su=0, D=1;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int y = 0; y < m; y++)
        {
            S += i+y;
        }
    }
    s = S;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            s += i*m;
            s -= (n-i)*m;
        }
        Sd = s;
        for (int y = 0; y < m; y++)
        {
            if (y == 0)
            {
                Su += Sd;
                continue;
            }
            Sd += y*n;
            Sd -= (m-y)*n;
            Su += Sd;
        }
    }
    Su /= 2;
    Su %= MOD;
    for (int i = 0; i < k-2; i++)
    {
        Su *= (m*n-i-2);
        Su %= MOD;
    }
    for (int i = 1; i <= k-2; i++)
    {
        D *= i;
        D %= MOD;
    }
    Su *= Pow(D, MOD-2);
    Su %= MOD;
    cout << Su;
    return 0;
}
