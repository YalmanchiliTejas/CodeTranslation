#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 3010;

int n,a[N];
ll dp[N][N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(int len=1;len<=n;len++)
        for(int i=1;i<=n-len+1;i++)
        {
            int l = i;
            int r = i+len-1;

            dp[l][r] = max( a[l] - dp[l+1][r]  , a[r] - dp[l][r-1] );
        }

    printf("%lld\n",dp[1][n]);
}
