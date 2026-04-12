# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;
const pair < int , int > DD[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
# define fi cin
# define fo cout
# define x first
# define y second
# define ll long long
# define IOS ios_base :: sync_with_stdio(0);cin.tie(0)
# define p(v) cerr << #v << " = " << v << '\n'
# define p2(v) cerr << #v << " = " << (complex < int > (v.x,v.y)) << '\n'
# define vi vector < int >
# define vl vector < ll >
# define pii pair < int , int >
# define mp make_pair
# define db long double
# define pb push_back
# define pdd pair < db , db >
int main(void)
{
    #ifdef CF
    freopen("input","r",stdin);
    #endif // CF
    srand(time(0));
    fo << fixed << setprecision(7);
    cerr << fixed << setprecision(7);
    int n,a,b,c,d;
    fi>>n>>a>>b>>c>>d;
    const int mod = 1e9 + 7;
    static int dp[1 << 20];
    dp[0] = 1;
    static int F[1 << 20];
    static int CC[1 << 20];
    auto pow = [&](int a,int b,int mod)
    {
        int ans = 1;
        while (b)
        {
            if (b & 1) ans = (1ll * ans * a) % mod;
            a = (1ll * a * a) % mod;
            b /= 2;
        }
        return ans;
    };
    F[0] = 1;
    for (int i = 1;i <= n;++i)
        F[i] = (1ll * F[i - 1] * i) % mod;
    for (int i = 0;i <= n;++i)
        CC[i] = pow(F[i],mod - 2,mod);
    auto C = [&](int n,int k)
    {
        if (!(0 <= k && k <= n))
            return 0;
        int ans = F[n];
        ans = (1ll * ans * CC[k]) % mod;
        ans = (1ll * ans * CC[n - k]) % mod;
        return ans;
    };
    static int inv[1 << 20];
    for (int i = 0;i <= n;++i)
        inv[i] = pow(i,mod - 2,mod);
    for (int i = a;i <= b;++i)
    {
        for (int j = n;j + 1;--j)
            {
                int cnt = 0;
                int coef = 1;
                for (int k = 1;k < c && k * i <= j;++k)
                    coef = (1ll * coef * C(n - (j - k * i),i)) % mod,coef = (1ll * coef * inv[k]) % mod;
                for (int k = c;k <= d && k * i <= j;++k)
                    coef = (1ll * coef * C(n - (j - k * i),i)) % mod,coef = (1ll * coef * inv[k]) % mod,cnt = (cnt + 1ll * coef * dp[j - k * i]) % mod;
                dp[j] = (dp[j] + cnt) % mod;
            }
    }
    fo << dp[n] << '\n';
    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
    return 0;
}
