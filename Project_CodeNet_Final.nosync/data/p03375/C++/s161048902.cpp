#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
int n, m;
int S[N][N], C[N][N], pw2[N * N], pww[N], ans;
int powi(int a, int b)
{
    int c = 1;
    for (; b; b >>= 1, a = 1ll * a * a % m)
        if (b & 1) c = 1ll * c * a % m;
    return c;
}
int main()
{
    cin >> n >> m;
    S[0][0] = 1;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j <= i; ++ j)
        {
            S[i + 1][j] = (S[i + 1][j] + 1ll * S[i][j] * (j + 1)) % m;
            S[i + 1][j + 1] = (S[i + 1][j + 1] + S[i][j]) % m;
        }
    for (int i = 0; i <= n; ++ i)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++ j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % m;
    }
    pw2[0] = 1;
    for (int i = 1; i <= n * n; ++ i) pw2[i] = (pw2[i - 1] + pw2[i - 1]) % m;
    for (int i = 0, j = 1; i <= n; ++ i)
    {
        pww[i] = powi(2, j);
        j = 2 * j % (m - 1);
    }
    for (int i = 0; i <= n; ++ i)
        for (int j = 0; j <= n - i; ++ j)
            ans = (ans + 1ll * C[n][i] * ((n - i) & 1 ? m - 1 : 1) % m * pww[i] % m * pw2[i * j] % m * S[n - i][j]) % m;
    cout << ans << endl;
}
