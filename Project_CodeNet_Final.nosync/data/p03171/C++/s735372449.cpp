#include <iostream>
using namespace std;
typedef long long int ll;
ll n, a[3001];
ll dp[3001][3001];
bool odd;
int main()
{
    scanf("%lld",&n);
    for(int i = 0; i < n; i++)scanf("%lld",&a[i]);
    odd = n%2;
    if(odd)
    {
        for(int i = 0 ; i<n;i++)
        {
            dp[i][i] = a[i];
        }
    }
    else
    {
        for(int i = 0 ; i<n;i++)
        {
            dp[i][i] = -a[i];
        }
    }
    //start dp
    for(int i = 1; i <= n-1; i++)
    {
        for(int l = 0; l+i<n; l++)
        {
            ll r = l+i;
            if((n-i)%2)
            {
                dp[l][r] = max(dp[l+1][r]+a[l],dp[l][r-1]+a[r]);
            }
            else
            {
                dp[l][r] = min(dp[l+1][r]-a[l],dp[l][r-1]-a[r]);
            }
        }
    }
    printf("%lld\n",dp[0][n-1]);
}
