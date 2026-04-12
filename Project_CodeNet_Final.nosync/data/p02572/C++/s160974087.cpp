#include<stdio.h>

int main()
{
    long long int n,i,ans=0,sum=0,mod=1000000007;
    scanf("%lld",&n);

    long long int a[n];

    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);

        sum=(sum+a[i])%mod;
    }

    for(i=0;i<n;i++)
    {
        sum=sum-a[i];

        if(sum<0)sum+=mod;

        ans = (ans +(a[i] * sum) ) % mod;
    }

    printf("%lld\n",ans);

}
