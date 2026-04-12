#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'

#define        MOD 998244353


ll binPow(ll a, ll q)
{
    a %= MOD;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2)) % MOD;
}

ll n;

ll ar[4000];

ll dp[3009][3009];


int main()
{
    ll i,j,k,l,m,s;

    sfl(n);
    sfl(s);

    for(i=0; i<n; i++)sfl(ar[i]);
    // dp[i][j] means upto i porjonto kototar sum j
    // so prottek i theke abar n-i+1 ta option ache
    for(i=1; i<=n; i++)
    {

        for(j=0; j<=s; j++)
        {

            if(ar[i-1] == j)dp[i][j] = i;
            if(j != s)dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
            if(ar[i-1] <= j)dp[i][j] = (dp[i][j] + dp[i-1][j-ar[i-1]])%MOD;
        }
    }

    ll fin = 0;

    for(i=1; i<=n; i++)fin = (fin + (dp[i][s]*(n-i+1)))%MOD;

    pfl(fin);
}
