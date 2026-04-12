#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

int f[10001][2][101];

char c[10001];
int n, k;

int F(int i, bool isLess, int m)
{
    if (i==n)
        return m == 0;
    int &r = f[i][isLess][m],j;
    if (r == -1)
    {
        r = 0;
        if (isLess)
        {
            for ( j=0; j<=9; ++j)
                r = (r + F(i+1, true, (m+j)%k)) % mod;
        }
        else
        {
            for ( j=0; j<c[i]-'0'; ++j)
                r = (r + F(i+1, true, (m+j)%k)) % mod;
            r = (r + F(i+1, false, (m+j) %k)) % mod;
        }
    }
    return r;
}

int main()
{
    for (int i=0; i<=10000; ++i)
        for (int j=0; j<2; ++j)
            for (int k=0; k<=100; ++k)
                f[i][j][k] = -1;
    scanf ( "%s %d", c, &k);
    n = strlen(c);
    cout << (F(0,0,0) + mod - 1) % mod;;
    return 0;
}
