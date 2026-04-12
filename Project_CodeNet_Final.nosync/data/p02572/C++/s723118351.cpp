#include<stdio.h>
#include<math.h>
int main()
{
    long long int i,n,s=0,ans=0,a[200009],m=1e9+7;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        ans+=s*a[i];
        ans%=m;
        s+=a[i];
        s%=m;
    }
    printf("%lld",ans);
}