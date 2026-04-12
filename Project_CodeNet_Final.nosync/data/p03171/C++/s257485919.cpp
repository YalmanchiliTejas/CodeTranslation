#include <stdio.h>
typedef long long ll;
ll dp[3005][3005],pre[3005];
ll a[3005];
ll max(ll x, ll y)
{
    if(x>=y)return x;
    return y;
}
int main(void) {
	// your code goes here
	int n,k,i;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
	    scanf("%lld",&a[i]);
	    pre[i] = pre[i-1] +a[i];
	}
	int len,j;
	for(i=1;i<=n;i++)dp[i][i] = a[i];
	for(i=1; i<n; i++)dp[i][i+1] =  max(a[i],a[i+1]);
	for(len= 3; len<=n; len++)
	{
	    for(i=1; i<=n;i++)
	    {
	        j = i  +  len  - 1;
	        if(j>n)break;
	        ll fir = pre[j] - pre[i] - dp[i+1][j]+ a[i];
	        ll sec = pre[j-1] -  pre[i-1] - dp[i][j-1] +  a[j];
	        dp[i][j] = max(fir,sec);
	    }
	}
	printf("%lld\n",2*dp[1][n] - pre[n]);
	return 0;
}

