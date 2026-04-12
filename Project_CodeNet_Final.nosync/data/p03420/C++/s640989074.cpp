#include <stdio.h>
int main()
{
    long long n,k,b,ans;
    scanf("%lld%lld",&n,&k);
    if (k==0) {printf("%lld",n*n);return(0);}
    ans=0;
    for (b=k;b<=n;b++)
    {
        if (n%b<k) ans+=(b-k)*(n/b); else
        ans+=(b-k)*(n/b)+(n%b)-k+1;
    }
    printf("%lld",ans);
    return(0);
}