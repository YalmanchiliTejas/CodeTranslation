#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    long long ans=0,sum=0;
    int n;scanf("%d",&n);
    while(n--)
    {
        int x;scanf("%d",&x);
        ans+=sum*x%mod;sum+=x;sum%=mod;
    }
    printf("%lld\n",ans%mod);
}
