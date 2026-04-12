#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned long long

#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(l,r) (((l)+(r))>>1)

const int MOD = (int) 1e9 + 7;
const double eps = (double) 1e-8;
const int maxn = (int) 2e5 + 20;
const double pi = (double) acos(-1.0);

LL po[maxn], inv[maxn];

LL fp(LL a, LL n, LL m)
{
    LL res = 1;
    while(n)
    {
        if(n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

LL C(int n, int m)
{
    return po[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int n, m, k;

void work()
{
    po[0] = 1;
    for(int i = 1; i < maxn; i++) po[i] = po[i - 1] * i % MOD;
    inv[maxn - 1] = fp(po[maxn - 1], MOD - 2, MOD);
    for(int i = maxn - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;

    cin >>n >>m >>k;

    LL ans = 0;

    LL mm = (LL) m * m % MOD;
    LL nn = (LL) n * n % MOD;
    for(int i = 1; i < n; i++)
    {
        LL tmp = (LL) i * (i + 1) / 2 % MOD;
        tmp = tmp * mm % MOD;
        ans += tmp;
    }
    for(int i = 1; i < m; i++)
    {
        LL tmp = (LL) i * (i + 1) / 2 % MOD;
        tmp = tmp * nn % MOD;
        ans += tmp;
    }
    ans %= MOD;
    ans = ans * C(n * m - 2, k - 2) % MOD;
    cout <<ans <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r" ,stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416

    int tc = 1;
//    scanf("%d", &tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}
