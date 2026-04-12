#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3010;
ll n, a[N], f[N][N]; //f[i][j]

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 1; i <= n; i++)
        f[i][i] = a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j + i <= n; j++)
            f[j][i + j] = max(a[j] - f[j + 1][i + j], a[i + j] - f[j][i + j - 1]);
    }
    printf("%lld\n", f[1][n]);
    return 0;
}