#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
#include <set>
#include <iomanip>
#include <time.h>
#include <list>
#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
#include <assert.h>
#include <memory.h>

#define mk make_pair
#define sc second
#define fr first
#define pb emplace_back
#define all(s) s.begin(), s.end()
#define sz(s) ( (int)s.size() )
#define int long long

using namespace std;

const int N = 1e3 + 5, mod = 1e9 + 7;

int dp[N], a, b, c, d, n, fc[N], ans = 0, old[N], Fc[N], D[N][N];

int binpow (int a, int b)
{
    if (b == 0)
        return 1;
    if (b & 1)
        return a * binpow(a, b - 1) % mod;

    int x = binpow(a, b >> 1);

    return x * x % mod;
}
int Cnk (int n, int k, int l)
{
    return fc[n] * D[l][k] % mod * Fc[n - k * l] % mod * Fc[l] % mod;
}
main ()
{
    cin >> n >> a >> b >> c >> d;

    fc[0] = 1;
    Fc[0] = 1;

    for (int i = 1; i <= n; i++)
        fc[i] = i * fc[i - 1] % mod,
        Fc[i] = binpow( fc[i], mod - 2 );


    for (int j = 1; j <= n; j++)
    {
        D[0][j] = 1;
        for (int i = 1; i <= d; i++)
            D[i][j] = D[i - 1][j] * fc[j] % mod;
        for (int i = 1; i <= d; i++)
            D[i][j] = binpow(D[i][j], mod - 2);
    }
    dp[0] = 1;
    old[0] = 1;

    for (int i = a; i <= b; i++)
    {
        for (int j = c; j <= d; j++)
        {
            for (int l = i * j; l <= n; l++)
            {
                dp[l] += old[l - i * j] * Cnk( n - l + i * j, i,  j );
                dp[l] %= mod;
            }
        }
        for (int l = 1; l <= n; l++)
            old[l] = dp[l];
    }
    cout << dp[n] << endl;
}
