#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define ROF(i,a,b) for(int i = (a);i>=(b);i--)
#define FR(i,a,b) for(int i = (a);i<(b);i++)
#define RF(i,a,b) for(int i = (a);i>(b);i--)
#define MST(a,x) memset(a,x,sizeof(a))
#define ll long long
#define PB push_back
#define PH push
#define MP make_pair
#define FT first
#define SD second
#define N 1005
#define M 51
#define INF 100000000000000007
#define MOD 1000000007
#define MOD2 1000000009
#define eps 1e-14
using namespace std;
inline int Max(int a,int b)
{
    return (((b-a)>>(32-1))&(a^b))^b;
}
inline int Min(int a,int b)
{
    return (((b-a)>>(32-1))&(a^b))^a;
}

ll dp[N][N];
ll fac[N][N];
ll invf[N][N];

ll rev(ll n) {
	ll ret = 1;
	ll exponent = MOD - 2;
	for (ll i = exponent; i; i >>= 1, n = n * n % MOD) {
		if (i & 1) {
			ret = ret * n % MOD;
		}
	}
	return ret;
}

void get_factorial_inverse(int n, int p) {
	fac[0][1] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i][1] = i * fac[i - 1][1] % p;
		for(int j = 2;j<=n;j++){
            fac[i][j] = fac[i][j-1]*fac[i][1]%p;
		}
	}
	invf[n][1] = rev(fac[n][1]);
	for (int i = n-1; i >= 0; --i) {
		invf[i][1] = invf[i + 1][1] * (i + 1) % p;
		for(int j = 2;j<=n;j++){
            invf[i][j] = invf[i][j-1]*invf[i][1]%p;
		}
	}
}

ll C(ll a,ll b)
{
    return fac[a][1]*invf[b][1]%MOD*invf[a-b][1]%MOD;
}
int main()
{
    int n,a,b,c,d;

    while(scanf("%d%d%d%d%d",&n,&a,&b,&c,&d)!=EOF)
    {
        get_factorial_inverse(n,MOD);

        dp[a-1][0] = 1;
        FOR(i,1,n)dp[a-1][i] = 0;
        FOR(i,a,b)
        {
            FOR(j,0,n)
            {
                dp[i][j] = dp[i-1][j];
                int num = c;
                while(j-num*i>=0&&num<=d)
                {
                    int pre = j-num*i;
                    dp[i][j] = (dp[i][j]+dp[i-1][j-num*i]*C(n-j+num*i,num*i)%MOD*fac[num*i][1]%MOD*invf[i][num]%MOD*invf[num][1]%MOD)%MOD;
                    num++;
                }
            }
        }
        printf("%I64d\n",dp[b][n]);
    }
    return 0;
}
