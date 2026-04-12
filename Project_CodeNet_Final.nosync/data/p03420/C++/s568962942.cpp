#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main()
{
    long long n,k;
    long long i,j;
    long long ans;
    while (scanf("%lld%lld",&n,&k)!=EOF)
    {
        ans=0;
        for (i=1;i<=n-k;i++)
        {
            j=i+k;
            ans+=(n/j)*i;
            if(n%j-k>=0)
                ans+=n%j-k+1;
        }
        if (k==0)
            ans=n*n;
        printf("%lld\n",ans);
    }
    return 0;
}