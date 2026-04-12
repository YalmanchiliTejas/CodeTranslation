#include <bits/stdc++.h>
using namespace std;

#define LL long long
typedef pair<int, int> pii;

template< typename T > inline void read(T &x)
{
    static char _c;
    static bool _f;

    x = 0;
    _f = 0;
    _c = getchar();

    while(_c < '0' || '9' < _c) {if(_c == '-') _f = true; _c = getchar();}
    while('0' <= _c && _c <= '9') {x = (x << 1) + (x << 3) + (_c & 15); _c = getchar();}
    if(_f) x = -x;
}

template < typename T > inline void Min(T &x, T y) {if(y < x) x = y;}
template < typename T > inline void Max(T &x, T y) {if(x < y) x = y;}


#define lowbit(x) ((x) & -(x))
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(l,r) ((l)+(((r)-(l))>>1))
#define fi first
#define se second
#define mk make_pair
#define pb push_back

const int INF = 0x3f3f3f3f;
const double pi = (double) acos(-1.0);
const double eps = (double) 1e-8;
//const int MOD = (int) 1e9 + 7;
const int MOD = (int) 998244353;
const int maxn = (int) 2e5 + 20;
const int maxm = (int) 1e6 + 20;

inline int sig(double x) {return x < -eps ? -1 : eps < x;}
LL fp(LL a, LL n, LL MOD)
{
    if(n < 0) a = fp(a, MOD - 2, MOD), n = -n;
    LL res = 1; for(; n; n >>= 1, a = a * a % MOD) if(n & 1) res = res * a % MOD; return res;
}

int n, m;
int a[3333];
LL dp[2][3333];

void work()
{
    cin >>n >>m;
    for(int i = 1; i <= n; i++) cin >>a[i];

    dp[0][0] = 1;

    LL ans, ans2, ans3;
    ans = ans2 = ans3 = 0;

    for(int i = 1; i <= n; i++)
    {
        int x = a[i];
        int p = i & 1, q = 1 - p;
        for(int j = 0; j <= m; j++) dp[p][j] = dp[q][j];

        for(int j = 0; j + x <= m; j++)
        {
            if(j != 0)
                dp[p][j + x] += dp[q][j];
            else
                dp[p][j + x] += (LL) dp[q][j] * i % MOD;

            if(dp[p][j + x] >= MOD) dp[p][j + x] -= MOD;
        }

        ans2 += dp[p][m];
        ans2 %= 998244353;
    }

    cout <<ans2 <<endl;
//
//    ans = (LL) dp[n & 1][m] * n % 998244353;
//
//    memset(dp[(n + 1) & 1], 0, sizeof(dp[(n + 1) & 1]));
//    dp[(n + 1) & 1][0] = 1;
//    for(int i = n; i >= 1; i--)
//    {
//        int x = a[i];
//        int p = i & 1, q = 1 - p;
//        for(int j = 0; j <= m; j++) dp[p][j] = dp[q][j];
//
//        for(int j = 0; j + x <= m; j++)
//        {
//            dp[p][j + x] += dp[q][j];
//
//            if(dp[p][j + x] >= 998244353) dp[p][j + x] -= 998244353;
//        }
//
//        ans3 += dp[p][m] ;
//        ans3 %= 998244353;
//
//        cout <<"3 :" <<i <<" " <<ans3 <<" " <<dp[p][m] <<" " <<dp[q][m] <<" " <<x <<endl;
//
//        cout <<"test :"; for(int j = 0; j <= m; j++) cout <<dp[q][j] <<" "; cout <<endl;
//        cout <<"test :"; for(int j = 0; j <= m; j++) cout <<dp[p][j] <<" "; cout <<endl;
//
//    }

//    cout <<ans3 <<endl;
//
//    ans = ans2 + ans3;
//    ans = (ans % 998244353 + 998244353) % 998244353;
//    cout <<ans <<endl;
}


int main(int argc, char **argv)
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
//    get_prime();
//    pre();
    int tc = 1;
//    read(tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}
