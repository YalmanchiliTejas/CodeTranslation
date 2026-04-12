#include<bits/stdc++.h>
using namespace std;

const long N = 3005;

long n;
long long f[N][N], g[N][N], a[N], sum = 0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long i = 1; i <= n; i++) cin >> a[i];
    for (long i = 1; i <= n; i++)
    {
        sum += a[i];
        f[i][i] = a[i];
        g[i][i] = 0;
    }
    for (long k = 1; k < n; k++)
    {
        for (long i = 1; i <= n - k; i++)
        {
            long j = i + k;
            long long tmp1 = a[i] + min(f[i + 1][j - 1], f[i + 2][j]);
            long long tmp2 = a[j] + min(f[i + 1][j - 1], f[i][j - 2]);
            f[i][j] = max(tmp1, tmp2);
        }
    }
    cout << f[1][n] + f[1][n] - sum;
    return 0;
}
