#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,ans,j,k,m=1000000007;
    scanf("%lld",&n);
    long long a[n+4],sum[n+4];
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sum[n]=0;
    for(i=n-1;i>0;i--){
        sum[i]=a[i+1]+sum[i+1];
        sum[i]%=m;
    }
    ans=0;
    for(i=1;i<n;i++){
        k=a[i]*sum[i];
        k%=m;
        ans=(ans+k+m)%m;
    }
    printf("%lld\n",ans);
    return 0;
}
