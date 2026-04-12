#include <bits/stdc++.h>
#define ll long long int
#define sd(x) scanf("%d",&x)
#define F first
#define S second
#define sd2(x,y) scanf("%d%d",&x,&y);
#define mp make_pair
#define pb push_back
#define pi pair <int, int > 
#define pl pair <ll, int >
#define infl (1ll << 60)
#define inf (1 << 30)
#define nax  200020
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

ll fact[nax];

ll exp(ll a, ll b)
{
    if(b == 0)
        return 1ll;
    if(b == 1)
        return a;
    if(b % 2 == 1)
        return a * exp(a, b - 1) % MOD;
    return exp(a * a % MOD, b/2);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m,k;
    sd2(n, m);
    sd(k);
    int p = n * m;
    ll i2 = exp(2, MOD - 2);
    fact[0] = 1;
    for(int i = 1; i <= p; i++)
        fact[i] = fact[i - 1] * i % MOD;

    ll mul = (fact[p - 2] * exp(fact[k - 2], MOD - 2) % MOD) * exp(fact[p - k], MOD - 2) % MOD;

    mul = mul * i2 % MOD;

    ll fx = 0;
    ll fy = 0;
    ll CN = n * 1ll * (n + 1);
    CN /= 2;
    ll CM = m * 1ll * (m + 1);
    CM /= 2;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            fx = (fx + CN - i * 1ll * (i + 1) - n * 1ll * i + 2ll * i * i + MOD * 1ll * MOD) % MOD;
            fy = (fy + CM - j * 1ll * (j + 1) - m * 1ll * j + 2ll * j * j + MOD * 1ll * MOD) % MOD;
        }
    }
    fx = fx * m % MOD;
    fy = fy * n % MOD;
    ll fans = (fx + fy) % MOD;
    fans = fans * mul % MOD;
    printf("%lld\n", fans);
    return 0;
}
