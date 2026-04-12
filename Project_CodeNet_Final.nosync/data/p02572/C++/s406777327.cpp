#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include<iostream>
using namespace std;
typedef long long ll;
ll a[1000005],s[1000005];
int main()
{
    ll b,c,ma=1231231231,ans=0,n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        ans+=(a[i]*((s[n]-s[i])%1000000007));
        ans%=1000000007;
    }
    printf("%lld\n",ans);

}
