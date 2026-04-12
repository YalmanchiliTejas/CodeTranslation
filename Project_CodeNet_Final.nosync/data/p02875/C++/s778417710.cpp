#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define lowbit(x) ((x) & -(x))
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define MID(l, r) (((l)+(r))>>1)
#define fi first
#define se second

typedef pair<int, int> pii;

const int maxn = (int) 1e7 + 20;
//const int MOD = 1e9 + 7;
const int MOD = 998244353;
const double eps = 1e-8;


template < typename T > inline void read(T &x)
{
    static bool f;
    static char ch;

    f = 0;
    x = 0;
    ch = getchar();

    while(ch < '0' || '9' < ch) {if(ch == '-') f = 1; ch = getchar();}
    while('0' <= ch && ch <= '9') {x = (x << 3) + (x << 1) + (ch & 15); ch = getchar();}

    if(f) x = -x;
}

LL gcd(LL a, LL b) {if(!b) return a; return gcd(b, a % b);}
LL fp(LL a, LL n, LL m = MOD) {LL res; for(res = 1; n; a = a * a % m, n >>= 1) if(n & 1) res = res * a % m; return res;}

template <typename T> inline T minx(T a, T b) {if(a < b) return a; return b;}
template <typename T> inline T maxx(T a, T b) {if(a < b) return b; return a;}

int n;
LL pow2[maxn];
LL fac[maxn], ifac[maxn];

LL comb(int n, int m)
{
    return fac[n] * ifac[n - m] % MOD * ifac[m] % MOD;
}

void work()
{
    cin >>n;
    pow2[0] = 1;
    fac[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        pow2[i] = pow2[i - 1] << 1;
        if(pow2[i] >= MOD) pow2[i] -= MOD;

        fac[i] = fac[i - 1] * i % MOD;
    }
    ifac[n] = fp(fac[n], MOD - 2, MOD);
    for(int i = n - 1; i >= 0; i--)
    {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }

    LL tmp = 0;
    for(int i = n / 2 + 1; i <= n; i++)
    {
        tmp += comb(n, i) * pow2[n - i] % MOD;
        if(tmp >= MOD) tmp -= MOD;
    }

    LL ans = fp(3, n, MOD) - tmp * 2;
    cout <<(ans % MOD + MOD) % MOD <<endl;
}


int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
#endif // yukihana0416

    int tc = 1;
//    read(tc);

    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}
