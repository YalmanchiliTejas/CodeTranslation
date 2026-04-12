#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int mod;

inline int add(int a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
    return a;
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % mod;
}

const int N = 5000;

int c[N][N];
int dp[N][N];
int ans[N];
int pw[N];
int real_pw[N];

inline int bin(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            a = mul(a, a);
            n /= 2;
        }
        else
        {
            res = mul(res, a);
            n--;
        }
    }
    return res;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    cin >> n;
    cin >> mod;
    c[0][0] = 1;
    dp[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i + 1 < N)
            {
                dp[i + 1][j] = add(dp[i + 1][j], add(mul(dp[i][j], j), dp[i][j]));
            }
            if (i + 1 < N && j + 1 < N)
            {
                dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
            }
            if (i)
            {
                c[i][j] = c[i - 1][j];
            }
            if (i && j)
            {
                c[i][j] = add(c[i][j], c[i - 1][j - 1]);
            }
        }
    }
    pw[0] = 1;
    real_pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = (pw[i - 1] + pw[i - 1]) % (mod - 1);
        real_pw[i] = (real_pw[i - 1] + real_pw[i - 1]) % mod;
    }
    for (int i = n; i >= 1; i--)
    {
        int ret = bin(2, pw[n - i]);
        int sum = 0;
        int num = real_pw[n - i];
        for (int j = 0; j <= i; j++)
        {
            sum = add(sum, mul(bin(num, j), dp[i][j]));
        }
        ans[i] = mul(c[n][i], mul(ret, sum));
        for (int j = i + 1; j <= n; j++)
        {
            ans[i] = add(ans[i], -mul(ans[j], c[j][i]));
        }
    }
    int result = bin(2, pw[n]);
    for (int i = 1; i <= n; i++)
    {
        result = add(result, -ans[i]);
    }
    cout << result << '\n';
}
