#include <bits/stdc++.h>

using namespace std;

#if 1
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

#define int long long

int mod;
int n;

long long inq(int a, int b)
{
    if (!b) return 1;
    int l = inq(a, b / 2);
    if (b % 2) return l * l % mod * a % mod;
    return l * l % mod;
}

int sti2[4000][4000];
int st2[4000 * 4000];
int st2euler[4000];
int stst2[4000];
int res[4000];
int cnk[4000][4000];
int rev[4000];
int fact[4000];

signed main()
{
    //freopen("input_02.txt", "r", stdin);
    //freopen("output_02.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n >> mod;
    //n = 3, mod = 1e9 + 7;
    st2[0] = 1, st2euler[0] = 1, rev[1] = 1, fact[0] = 1;
    for (int i = 2; i < 4000; i++) rev[i] = (mod - rev[mod % i] * (mod / i)) % mod;
    for (int i = 1; i < 4000 * 4000; i++) st2[i] = st2[i - 1] * 2 % mod;
    for (int i = 1; i < 4000; i++) st2euler[i] = st2euler[i - 1] * 2 % (mod - 1), fact[i] = fact[i - 1] * i % mod;
    for (int i = 0; i < 4000; i++) stst2[i] = inq(2, st2euler[i]);
    for (int i = 0; i < 4000; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0) sti2[i][j] = (i == 0);
            else sti2[i][j] = (sti2[i - 1][j - 1] + j * sti2[i - 1][j]) % mod;
            if (j) cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % mod;
            else cnk[i][j] = 1;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            res[i] = (res[i] + (sti2[i][j + 1] * (j + 1) % mod + sti2[i][j]) * st2[j * (n - i)] % mod * stst2[n - i]) % mod;
            //cout << i << " " << j << " " << (sti2[i][j + 1] * (j + 1) + sti2[i][j]) * st2[j * (n - i)] % mod * stst2[n - i] % mod << endl;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        //cout << res[i] << endl;
        if (i % 2 == 0)
            ans = (ans + cnk[n][i] * res[i]) % mod;
        else
            ans = (ans + mod * mod - cnk[n][i] * res[i]) % mod;
    }
    cout << ans;
}
