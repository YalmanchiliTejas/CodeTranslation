#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int maxn = 3003;

long long add(long long a, long long b)
{
    a += b;
    if (a >= mod)
        a -= mod;

    return a;
}

long long dp1[maxn][maxn], dp2[maxn][maxn], sum[maxn];
int n, s;
int a[maxn];
void read()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

long long f(int l, int r)
{
    if (l == r)
    return a[l] == s;

    int mid = (l + r) / 2;
    long long ans = add(f(l, mid), f(mid + 1, r));

    for (int i = 0; i <= s; i++)
        dp1[mid+1][i] = 0;
    dp1[mid+1][0] = 1;

    for (int i = mid; i >= l; i--)
    for (int j = 0; j <= s; j++)
    dp1[i][j] = add(dp1[i+1][j], (j-a[i] >= 0) ? dp1[i+1][j-a[i]] : 0);

    for (int i = 0; i <= s; i++)
        dp2[mid][i] = 0;
    dp2[mid][0] = 1;

    for (int i = mid+1; i <= r; i++)
        for (int j = 0; j <= s; j++)
        dp2[i][j] = add(dp2[i-1][j], (j-a[i] >= 0) ? dp2[i-1][j-a[i]] : 0);

    for (int i = 0; i <= s; i++)
    {
        sum[i] = 0;
        for (int j = mid+1; j <= r; j++)
            sum[i] = add(sum[i], dp2[j][i]);
    }

    for (int i = l; i <= mid; i++)
        for (int j = 0; j <= s; j++)
        ans = add(ans, dp1[i][j] * sum[s-j] % mod);

    return ans;
}

void solve()
{
    cout << f(1, n) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    read();
    solve();
}
