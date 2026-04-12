#include<bits/stdc++.h>
using namespace std;

main()
{
    long long n,k;
    scanf("%lld %lld",&n,&k);
    long long ans=0;
    for(long long b=k+1;b<=n;b++)
    {
        long long mx_q=n/b;
        ans+=(mx_q)*(b-k);
        ans+=max(n%b-k+1,0LL);
        //printf("%lld\n",ans);
    }
    if(k==0)
        ans=n*n;
    printf("%lld\n",ans);
}
